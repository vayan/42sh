/*
** buffer.c for 42sh in /home/maurin_t//mesfonction
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Apr 26 15:59:13 2011 timothee maurin
** Last update Sat May 14 15:35:50 2011 timothee maurin
*/

#include        <unistd.h>
#include        <stdio.h>
#include        <sys/ioctl.h>
#include        <sys/types.h>
#include        <termcap.h>
#include        <termios.h>
#include        <stdlib.h>
#include        <curses.h>
#include        <term.h>
#include        <signal.h>
#include	<string.h>
#include	"shell.h"
#include	"prototype.h"
#include	"xmalloc.h"
#include	"termcap_include.h"

void	func_remove(char *cha, int *i, int *pos, char *buf)
{
  if (*i > 0)
    {
      if (*pos != *i && is_del(cha))
	{
	  my_strcpy(&(buf[*pos]), &(buf[*pos + 1]));
	  (*i)--;
	}
      if (cha[0] == 127 && *pos > 0)
	{
	  if (*pos != *i)
	    my_strcpy(&(buf[*pos - 1]), &(buf[*pos]));
	  (*pos)--;
	  (*i)--;
	  buf[(*i)] = '\0';
	}
    }
  place_cursor_del((*i), *pos, buf, 0);
  xwrite(0, "$>", 2);
  my_putstr_del(buf);
  if ((cur_pos(buf, *i) % nbr_column()) == 0 && cha[1] != 127)
    xwrite(0, " \b", 2);
  if (*i != *pos)
    place_cursor(*i, *pos, buf);
}

char			*other_cha(char cha, char *buf, int *pos, int *i)
{
  if (*i < 8192)
    {
      (*pos)++;
      (*i)++;
      buf[*i] = '\0';
      if (cha != '\n')
	{
	  my_strcpy_buf(&(buf[*pos]), &(buf[(*pos) - 1]));
	  buf[*pos - 1] = cha;
	  if ((*i) != (*pos))
	    {
	      exec_str("cd");
	      my_putstr_buf(&(buf[*pos - 1]), *i, *pos, buf);
	      place_cursor((*i), (*pos), buf);
	    }
	  else
	    {
	      exec_str("im");
	      xwrite(0, &cha, 1);
	      exec_str("ei");
	    }
	}
    }
  else
    exec_str("bl");
  return (buf);
}

void	func_fleche(char *cha, int *i, int *pos, char **buf)
{
  int	tmp;

  if (cha[2] == 68 && *pos > 0)
    {
      (*pos)--;
      if (!((cur_pos(*buf, *pos) + cur_pos(*buf, (*pos) + 1)
	     - cur_pos(*buf, *pos)) % nbr_column())
	  && (cur_pos(*buf, *pos) + cur_pos(*buf, (*pos) + 1)
	      - cur_pos(*buf, *pos)) / nbr_column())
	exec_str("up");
      exec_parm("ch", (cur_pos(*buf, *pos)) % (nbr_column()));
    }
  if (cha[2] == 67 && *pos < *i)
    {
      (*pos)++;
      if (!((cur_pos(*buf, *pos)) % nbr_column()))
        exec_str("do");
      exec_parm("ch", (cur_pos(*buf, *pos)) % (nbr_column()));
    }
  if (cha[2] == 65 || cha[2] == 66)
    funct_histo(cha, i, pos, buf);
}

void		func_special(char *cha, int *i, int *pos, char **buf)
{
  if (is_del(cha) || cha[0] == 127)
    func_remove(cha, i, pos, *buf);
  else if (cha[0] == 27 && cha[1] == 91
	   && (cha[2] == 65 || cha[2] == 66 || cha[2] == 67 || cha[2] == 68))
    func_fleche(cha, i, pos, buf);
  else if (cha[0] == 27 && cha[1] == 91 && cha[2] == 90)
    other_cha(9, *buf, pos, i);
}
  /* printf(">>%d %d %d %d %d %d<<\n", cha[0], cha[1], cha[2], cha[3], cha[4], cha[5]); */

void			get_next_comm(t_shell *shell, struct termios *term2)
{
  int			pos = 0;
  int			i = 0;
  char			*cha;

  init_new_cmd(shell);
  recup_com(shell, 0);
  shell->commande->buffer = xmalloc(8193 * sizeof(*cha));
  free_buf(shell->commande->buffer, 0);
  cha = xmalloc(2 * sizeof(*cha));
  while (cha[0] != '\n')
    {
      free(cha);
      cha = get_touche(term2);
      if (verif_touche(cha))
	func_special(cha, &i, &pos, &(shell->commande->buffer));
      else
	shell->commande->buffer = other_cha(cha[0],
					    shell->commande->buffer, &pos, &i);
      if (nbr_column() && (!(verif_touche(cha))
			   || (cha[0] == 27 && cha[1] == 91 && cha[2] == 90))
	  && i == pos
	  && cur_pos(shell->commande->buffer, i) % nbr_column() == 0)
	xwrite(0, "\n", 1);
    }
  place_cursor_del(i, pos, shell->commande->buffer, 2);
  free_buf(shell->commande->buffer, 1);
  xwrite(0, "\n", 1);
  free(cha);
}
