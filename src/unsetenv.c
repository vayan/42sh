/*
** unsetenv.c for  in /home/vailla_y//Projet/42sh/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Wed May  4 15:39:52 2011 yann vaillant
** Last update Thu May 19 19:25:24 2011 timothee maurin
*/

#include        <string.h>
#include        <stdlib.h>
#include        <stdio.h>
#include        "shell.h"
#include        "graph.h"
#include        "xmalloc.h"

int     my_unsetenv(char *value, char **env)
{
  int   x = 0;
  int   max = go_end_env(env);
  char  *name;

  if (value == NULL)
    return (-1);
  while (env[x])
    {
      name = get_name_env(env[x]);
      if (strcmp(value, name) == 0)
        {
          free(env[x]);
          while (env[x])
            {
              env[x] = env[x + 1];
              if (env[x])
                x++;
            }
          free(name);
          return (0);
	}
      free(name);
      x++;
    }
  return (0);
}
