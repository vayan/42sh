/*
** xpipe.c for minishell in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 18:24:04 2011 timothee maurin
** Last update Tue Jun  7 18:29:23 2011 maxime constantinian
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "shell.h"
#include "prototype.h"

int		check_if_in_pipe(int tab, int **sauve)
{
  int		i;

  i = 0;
  while (sauve && sauve[i])
    {
      if (sauve[i][0] == tab || sauve[i][1] == tab)
	return (0);
      i++;
    }
  return (tab);
}

int		*xpipe(int *tab, int mode)
{
  static int	**sauve;
  static int	i;
  int		ret = 0;

  if (mode == 0)
    {
      if (pipe(tab) == -1)
	return ((int *)(fprintf(stderr, "42sh: Pipe : %s\n", strerror(errno))
			* 0));
      if (sauve == 0)
	sauve = xmalloc(sizeof(*sauve) * 2);
      else
	sauve = xrealloc(sauve, sizeof(*sauve) * (i + 2));
      sauve[i] = tab;
      sauve[i + 1] = 0;
      i++;
    }
  else
    {
      ret = check_if_in_pipe(*tab, sauve);
      xfree(sauve);
      sauve = 0 + (int **)(i = 0);
      return ((int *)ret);
    }
  return (tab);
}
