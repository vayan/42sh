/*
** buffer_histo.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Mon May  9 18:47:47 2011 timothee maurin
** Last update Tue May 10 21:48:01 2011 timothee maurin
*/

#include			<string.h>
#include			<stdlib.h>
#include			"shell.h"
#include			"prototype.h"

t_commande_root			*recup_com(t_shell *shell, int test)
{
  static t_commande_root	*save;

  if (test == 0)
    save = shell->commande;
  else if (test == 1 && save != 0)
    save = save->next_histo;
  else if (test == 2 && save != 0)
    save = save->before_histo;
  return (save);
}

char				*free_buf(char *buf, int test)
{
  static char			*save;

  if (save != 0 && save != buf && test == 1)
    {
      free(save);
      save = 0;
    }
  else if (test == 0)
    save = buf;
  return (save);
}

void				reaf(int *i, int *pos, char *buf)
{
  place_cursor(*i, 0);
  exec_str("cd");
  xwrite(0, buf, strlen(buf));
  *i = strlen(buf);
  *pos =  *i;
}

void				funct_histo(char *cha, int *i,
					    int *pos, char **buf)
{
  char				*tmp;
  t_commande_root		*com;

  com = recup_com(0, 3);
  if (cha[2] == 66 && com->next_histo != 0)
    {
      if (com->next_histo->next_histo == 0 && (tmp = free_buf(0, 2)))
	{
	  *buf = tmp;
	  com = recup_com(0, 1);
	}
      else if (com->next_histo->next_histo != 0)
	{
	  com = recup_com(0, 1);
	  *buf = com->buffer;
	}
      reaf(i, pos, *buf);
    }
  if (cha[2] == 65 && com->before_histo != 0)
    {
      com = recup_com(0, 2);
      *buf = com->buffer;
      reaf(i, pos, *buf);
    }
}
