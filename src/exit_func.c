/*
** exit_func.c for exit_func in /home/schoen_a//42sh/42sh/src
** 
** Made by arnaud schoenher
** Login   <schoen_a@epitech.net>
** 
** Started on  Wed May  4 15:55:26 2011 arnaud schoenher
** Last update Thu May 19 20:01:17 2011 maxime constantinian
*/

#include        <string.h>
#include        <stdlib.h>
#include        <stdio.h>
#include        "shell.h"
#include        "graph.h"
#include        "xmalloc.h"

int	exit_func(char **av, char **env)
{
  char *last_exit;
  int	end_av;

  end_av = go_end_env(av);
  if (end_av == 1)
    {
      last_exit = my_get_env("?", env);
      if (last_exit != 0)
	exit(my_getnbr(last_exit));
      exit(0);
    }
  if (end_av > 1)
    exit(my_getnbr(av[1]));
  return (0);
}
