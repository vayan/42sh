/*
** set_env.c for  in /home/vailla_y//Projet/42sh/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Fri Apr 29 10:39:58 2011 yann vaillant
** Last update Thu May 19 13:05:34 2011 Vaillant Yann
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include        "shell.h"
#include        "graph.h"
#include        "xmalloc.h"

void	aff_env(char **env)
{
  int	x = 0;

  while (env[x])
    printf("%s\n", env[x++]);
}

char *concet_env(char *add_to_env, char *name, char *value)
{
  add_to_env = xmalloc ((strlen(name) + strlen(value) + 2));
  strcat(add_to_env, name);
  strcat(add_to_env, "=");
  strcat(add_to_env, value);
  return (add_to_env);
}

int	check_if_no_arg(char **value);
{
  if (value || value[0] || value[1])
    {
      aff_env(env);
      return (1);
    }
  return (0);
}

char	**my_setenv(char **value, char **env)
{
  int	x;
  char	*add_to_env;
  char	*name_env;
  int	i = 0;

  if (check_if_no_arg(value) == 1)
    return (1);
  x = go_end_env(env);
  add_to_env = concet_env(add_to_env, value[1], value[2]);
  while (env[i])
    {
      name_env = get_name_env(env[i]);
      if (strcmp(name_env, value[1]) == 0)
	{
	  free(env[i]);
	  env[i] = add_to_env;
	  free(name_env);
	  return (env);
	}
      free(name_env);
      i++;
    }
  env = realloc(env, (x + 2) * sizeof(*env));
  env[x] = add_to_env;
  return (env[x + 1] = 0);
}
