/*
** xfork.c for xfork in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 18:27:42 2011 timothee maurin
** Last update Sat Jun 11 18:26:59 2011 maxime constantinian
*/

#include <wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "shell.h"
#include "prototype.h"

int		kill_all(int *sauv, int i)
{
  int		j = 0;
  int		ret = 0;
  int		status = 0;

  while (sauv && j < i)
    {
      if (kill(sauv[j], SIGKILL) == -1)
	ret++;
      if (waitpid(sauv[j], &status, WUNTRACED) == -1)
	ret++;
      j++;
    }
  return (ret);
}

int		xfork(int mode)
{
  static int	*sauv = 0;
  static int	i = 0;
  int		pid;

  if (mode == 0)
    {
      pid = fork();
      if (pid == -1)
	fprintf(stderr, "42sh: Fork : %s\n", strerror(errno));
      if (sauv == 0)
	sauv = xmalloc(sizeof(*sauv) * 2);
      else
	sauv = xrealloc(sauv, sizeof(*sauv) * (i + 2));
      sauv[i] = pid;
      sauv[i + 1] = 0;
      i++;
    }
  else
    {
      kill_all(sauv, i);
      xfree(sauv);
      return ((i = 0) + (int)(sauv = 0));
    }
  return (pid);
}
