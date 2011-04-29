/*
** buffer.c for 42sh in /home/maurin_t//mesfonction
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Apr 26 15:59:13 2011 timothee maurin
** Last update Fri Apr 29 18:56:11 2011 timothee maurin
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
#include	"xmalloc.h"

int	verif_touche(char *cha)
{
  if (cha[0] < ' ' || cha[0] == 127)
    return (1);
  else
    return (0);
}

int	is_del(char *cha)
{
  if (cha[0] == 27 && cha[1] == 91 && cha[2] == 51 && cha[3] == 126)
    return (1);
  else
    return (0);
}

void		clear_it(int nbr_line, int *pos, int *i)
{
  static int	max;
  int		tmp;

  tmp = 0;
  if (max < ((*i) + 2) / (nbr_column() + 1))
    max = (((*i) + 2) / (nbr_column() + 1));
  while (tmp < max - ((*pos + 2)) / (nbr_column() - 1))
    {
      exec_parm("do", 1);
      tmp++;
    }
  tmp = max;
  while (tmp > 0)
    {
      exec_str("cr");
      exec_str("cd");
      exec_parm("up", 1);
      tmp--;
    }
  exec_str("cr");
  exec_str("cd");
}

int	nbr_column()
{
  struct winsize        w;

  if (ioctl(0, TIOCGWINSZ, &w) == -1)
    fprintf(stderr, "ioclt error\n");
  return (w.ws_col);
}

void	func_remove(char *cha, int *i, int *pos, char *buf)
{
  int	a;

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
	    my_strcpy(&(buf[*pos]), &(buf[*pos + 1]));
	  (*pos)--;
	  (*i)--;
	  buf[(*i)] = '\0';
	}
    }
  clear_it((strlen(buf)) / nbr_column(), pos, i);
  write(0, "$>", 2);
  write(0, buf, strlen(buf));
  if (((strlen(buf) + 2) % nbr_column()) == 0 && cha[1] != 127)
    write(0, " \b", 2);
  a = 0;
  while (a++ < *i - *pos)
    {
      if (((*i - a + 3) % (nbr_column())) == 0)
      	{
	  if ((*i - a + 3) / (nbr_column()))
	    {
	      exec_parm("up", 1);
	      exec_parm("ch", nbr_column() + 1);
	    }
      	}
      else
      	write(0, "\b", 1);
    }
}

char			*other_cha(char cha, char *buf, int *pos, int *i)
{
  static int		buffer_size = 1024;

  if (!(verif_touche(&cha)))
    {
      (*pos)++;
      (*i)++;
    }
  if (*i >= buffer_size)
    {
      buffer_size += 1024;
      buf = realloc(buf, buffer_size);
    }
  buf[*i] = '\0';
  if (cha != '\n')
    {
      my_strcpy_buf(&(buf[*pos]), &(buf[(*pos) - 1]));
      buf[*pos - 1] = cha;
      exec_str("im");
      write(0, &cha, 1);
      exec_str("ei");
    }
  return (buf);
}

void	func_fleche(char *cha, int *i, int *pos, char *buf)
{
  if (cha[2] == 68 && *pos > 0)
    {
      if ((*pos + 2) % nbr_column() == 0 && *pos != 0)
	{
	  if ((*pos + 2) / nbr_column())
	    {
	      exec_str("up");
	      exec_parm("ch", nbr_column() - 1);
	    }
	}
      else
	exec_str("le");
      (*pos)--;
    }
  if (cha[2] == 67 && *pos < *i)
    {

      exec_str("nd");
      (*pos)++;
      if ((*pos + 2) % nbr_column() == 0 && *pos != *i)
	exec_str("do");
    }
}

void	func_special(char *cha, int *i, int *pos, char *buf)
{
  if (is_del(cha) || cha[0] == 127)
    func_remove(cha, i, pos, buf);
  else if (cha[0] == 27 && cha[1] == 91
	   && (cha[2] == 65 || cha[2] == 66 || cha[2] == 67 || cha[2] == 68))
    func_fleche(cha, i, pos, buf);
  /*  else
      printf(">>%d %d %d %d %d %d<<\n", cha[0], cha[1], cha[2], cha[3], cha[4], cha[5]);*/
}

void			get_next_comm(t_shell *shell, struct termios *term2)
{
  int			pos;
  int			i;
  char			*cha;

  pos = 0;
  i = 0;
  shell->commande->buffer = xmalloc(1024 * sizeof(*cha));
  cha = xmalloc(2 * sizeof(*cha));
  write(0, "$>", 2);
  while (cha[0] != '\n')
    {
      free(cha);
      cha = get_touche(term2);
      if (verif_touche(cha))
	func_special(cha, &i, &pos, shell->commande->buffer);
      else
	shell->commande->buffer = other_cha(cha[0],
					    shell->commande->buffer, &pos, &i);
      if (((strlen(shell->commande->buffer) + 2) % nbr_column()) == 0
	  && !(verif_touche(cha)))
	write(0, "\n", 1);
    }
  free(cha);
}
