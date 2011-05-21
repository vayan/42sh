/*
** cur_pos.c for  in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Thu May 12 14:20:09 2011 timothee maurin
** Last update Sat May 21 21:19:42 2011 timothee maurin
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "prototype.h"

int			size_prompt()
{
  int			ret;
  char			*tmp;
  static t_shell	*shell;

  if (shell == 0)
    shell = recup_shell(0);
  tmp = get_prompt(shell);
  ret = strlen(tmp);
  free(tmp);
  return (ret);
}

int			cur_pos(char *buf, int i, int test)
{
  int			p = -1;
  int			tmp;
  int			ret;
  static int		retsave;

  if (test == 0)
    retsave = size_prompt();
  ret = retsave;
  while (++p < i)
    if (buf && buf[p] == 9)
      {
	tmp = (ret % nbr_column()) % 8;
	if (ret % nbr_column() + 8 - tmp < nbr_column())
	  ret += 8 - tmp;
	else
	  ret += nbr_column() - ret % nbr_column();
      }
    else
      ret++;
  return (ret);
}
