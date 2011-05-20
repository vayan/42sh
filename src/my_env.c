/*
** my_env.c for me env in /home/pugeat_j/
** 
** Made by justin pugeat
** Login   <pugeat_j@epitech.net>
** 
** Started on  Fri May  6 14:44:35 2011 justin pugeat
** Last update Fri May 20 17:56:12 2011 maxime constantinian
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "graph.h"
#include "xmalloc.h"

int	check_equal(char *str)
{
  int	i = 0;

  while (str[i])
    {
      if (str[i] == '=')
	return (0);
      i++;
    }
  return (1);
}

int	size_env(char **av)
{
  int	i = 0;

  while (av[i])
    i++;
  return (i);
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

int	strlen_equal(char *av)
{
  int	i = 0;

  while (av[i])
    {
      if (av[i] == '=')
	return (i);
      i++;
    }
  return (0);
}

int	env_funct(char **av, char **env, int *tab)
{
  int		i = 0;
  int		j = 0;
  int		len = 0;
  char		**new_env;

  if (av[i] == 0)
    return (aff_env(env, tab));
  if (strcmp(av[i], "-i") != 0)
    new_env = copy(env, new_env);
  else if (strcmp(av[i], "-i") == 0 && av[i + 1] == 0)
    return (0);
  else
    new_env = xmalloc(1 * sizeof(*new_env));
  while (av[++i])
    if (check_equal(av[i + 1]) == 0)
      {
	len = size_env(new_env);
	new_env = realloc(new_env, sizeof(*new_env) * (len + 2));
	new_env[len] = strdup(av[i + 1]);
	new_env[len + 1] = 0;
      }
    else
      return (exec_in_builtin(av[i], recup_shell(0), new_env, tab));
  return (aff_env(new_env, tab));
}
