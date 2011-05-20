/*
** unsetenv.c for  in /home/vailla_y//Projet/42sh/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Wed May  4 15:39:52 2011 yann vaillant
** Last update Fri May 20 15:21:19 2011 Vaillant Yann
*/

#include        <string.h>
#include        <stdlib.h>
#include        <stdio.h>
#include        "shell.h"
#include        "graph.h"
#include        "xmalloc.h"

int	remove_env(char ***value, char ***env, int *x, int *z)
{
  char  *name;

  name = get_name_env((*env)[(*x)]);
  if (strcmp((*value)[(*z)], (name)) == 0)
    {
      free((*env)[(*x)]);
      while ((*env)[(*x)])
	{
	  (*env)[(*x)] = (*env)[(*x) + 1];
	  if ((*env)[(*x)])
	    (*x)++;
	}
      free(name);
    }
  else
    free(name);
}

int     my_unsetenv(char **value, char **env)
{
  int   x = 0;
  int	z = 1;
  int   max = go_end_env(env);

  if (value == NULL)
    return (-1);
  while (value[z])
    {
      max = go_end_env(env);
      x = 0;
      while (env[x])
	{
	  remove_env(&(value), &(env), &x, &z);
	  x++;
	}
      z++;
    }
  return (0);
}
