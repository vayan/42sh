/*
** unsetenv.c for  in /home/vailla_y//Projet/42sh/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Wed May  4 15:39:52 2011 yann vaillant
** Last update Sat May 21 22:10:21 2011 Vaillant Yann
*/

#include        <string.h>
#include        <stdlib.h>
#include        <stdio.h>
#include        "shell.h"
#include        "graph.h"
#include        "xmalloc.h"

int	remove_env(char ***value, char ***env, int x, int *z)
{
  char  *name;
  int	i = 0;
  int	ret = 0;

  name = get_name_env((*env)[x]);
  if (my_strcmp_star((*value)[(*z)], (name)) == 0)
    {
      i = x;
      ret = 1;
      while ((*env)[x])
	{
	  if (i == x)
	    free((*env)[x]);
	  (*env)[x] = (*env)[x + 1];
	  if ((*env)[x])
	    x++;
	}
      free(name);
    }
  else
    free(name);
  return (ret);
}

int     my_unsetenv(char **value, char **env)
{
  int   x = 0;
  int	z = 1;
  int	ret = 0;

  if (value == NULL)
    return (-1);
  while (value[z])
    {
      x = 0;
      while (env[x])
	{
	  ret = remove_env(&(value), &(env), x, &z);
	  if (ret == 0)
	    x++;
	}
      z++;
    }
  return (0);
}
