/*
** cur_pos.c for  in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Thu May 12 14:20:09 2011 timothee maurin
** Last update Fri May 20 15:57:09 2011 timothee maurin
*/

#include <string.h>
#include "shell.h"
#include "prototype.h"

int			cur_pos(char *buf, int i, int test)
{
  static t_shell	*shell;
  int			p;
  int			tmp;
  int			ret;
  static int		retsave;

  if (shell == 0)
    shell = recup_shell(0);
  if (test == 0)
    retsave = strlen(get_prompt(shell));
  ret = retsave;
  p = -1;
  while (++p < i)
    if (buf && buf[p] == 9)
      {
	tmp = ret % nbr_column();
	tmp = tmp % 8;
	if (ret % nbr_column() + 8 - tmp < nbr_column())
	  ret += 8 - tmp;
	else
	  ret += nbr_column() - ret % nbr_column();
      }
    else
      ret++;
  return (ret);
}
