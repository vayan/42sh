/*
** my_env.c for me env in /home/pugeat_j/
** 
** Made by justin pugeat
** Login   <pugeat_j@epitech.net>
** 
** Started on  Fri May  6 14:44:35 2011 justin pugeat
** Last update Sun May 22 22:07:18 2011 timothee maurin
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "graph.h"
#include "xmalloc.h"
#include "prototype.h"

int	check_equal(char *str)
{
  int	i = 0;

  while (str && str[i])
    {
      if (str[i] == '=')
	return (0);
      i++;
    }
  return (1);
}

int	get_nbr_ligne(char **env)
{
  int   x = 0;

  while (env[x])
    x++;
  return (x);
}

char	**copy(char **env, char **new_env)
{
  int	x = get_nbr_ligne(env);

  new_env = xmalloc((x + 1) * sizeof(*(new_env)));
  while (x--)
    new_env[x] = my_strcopynalloc(env[x]);
  return (new_env);
}

int	aff_free_env(char **new_env, int *tab)
{
  aff_env(new_env, tab);
  free_tab(new_env);
  return (0);
}

int	env_funct(char **av, char **env, int *tab)
{
  int		i = 0;
  int		len = 0;
  char		**new_env = 0;

  if (av[1] == 0)
    return (aff_env(env, tab));
  if (strcmp(av[1], "-i") != 0)
    new_env = copy(env, new_env);
  else if (strcmp(av[1], "-i") == 0 && av[2] == 0)
    return (0);
  else
    new_env = xmalloc(1 * sizeof(*new_env));
  while (av[++i])
    if (check_equal(av[i]) == 0)
      {
	len = size_env(new_env);
	new_env = realloc(new_env, sizeof(*new_env) * (len + 2));
	new_env[len] = strdup(av[i]);
	new_env[len + 1] = 0;
      }
    else if (strcmp(av[i], "-i") != 0)
      return (exec_in_builtin(&(av[i]), recup_shell(0), new_env, tab));
  return (aff_free_env(new_env, tab));
}
