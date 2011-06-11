/*
** set_env.c for  in /home/vailla_y//Projet/42sh/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Fri Apr 29 10:39:58 2011 yann vaillant
** Last update Sat Jun 11 18:56:08 2011 maxime constantinian
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include        "shell.h"
#include        "graph.h"
#include        "xmalloc.h"
#include	"prototype.h"

int	aff_env(char **env, int *tab)
{
  int	x = 0;

  while (env[x])
    {
      xwrite(tab[1], env[x], strlen(env[x]));
      xwrite(tab[1], "\n", 1);
      x++;
    }
  return (0);
}

char *concet_env(char *add_to_env, char *name, char *value)
{
  add_to_env = xmalloc ((strlen(name) + strlen(value) + 2));
  strcat(add_to_env, name);
  strcat(add_to_env, "=");
  strcat(add_to_env, value);
  return (add_to_env);
}

int	check_if_no_arg(char **value, char **env, int *tab)
{
  if (value && value[0] && value[1] == 0)
    {
      aff_env(env, tab);
      return (1);
    }
  return (0);
}

char	*if_not_value(char **value, char *add_to_env)
{
  if (value[2])
    add_to_env = concet_env(add_to_env, value[1], value[2]);
  else
    add_to_env = concet_env(add_to_env, value[1], "");
  return (add_to_env);
}

int	my_setenv(char **value, char **env, int *tab)
{
  int	x;
  char	*add_to_env = 0;
  char	*name_env;
  int	i = -1;
  t_shell *shell = recup_shell(0);

  if (check_if_no_arg(value, env, tab) == 1)
    return (0);
  x = go_end_env(env);
  add_to_env = if_not_value(value, add_to_env);
  while (env[++i] && ((name_env = get_name_env(env[i])) || 1))
    {
      if (strcmp(name_env, value[1]) == 0)
	{
	  free(env[i]);
	  env[i] = add_to_env;
	  free(name_env);
	  return (0);
	}
      free(name_env);
    }
  env = xrealloc(env, (x + 2) * sizeof(*env));
  env[x] = add_to_env + 0 * *(env[x + 1] = 0);
  shell->env = env;
  return (0);
}
