/*
** my_env.c for me env in /home/pugeat_j/
** 
** Made by justin pugeat
** Login   <pugeat_j@epitech.net>
** 
** Started on  Fri May  6 14:44:35 2011 justin pugeat
** Last update Tue May 17 19:11:20 2011 justin pugeat
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "graph.h"
#include "xmalloc.h"

void	aff_env(char **env)
{
  int	j = 0;

  while (env[j])
    {
      printf("%s\n", env[j]);
      j++;
    }
}

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

int	env_funct(char **av, char **env)
{
  int		i = 0;
  int		j = 0;
  int		len = 0;
  char		**new_env;
  char		*len;
  char		**value;

  new_env = copy(env, new_env);
  while (av[i])
    {
      if (strcmp(av[i], "env") == 0 && av[i + 1] == 0)
	{
	  aff_env(env);
	  return (0);
	}
      else if (strcmp(av[i], "-i") == 0 && av[i + 1] == 0)
	return (0);
      else if (strcmp(av[i], "-i") == 0 && check_equal(av[i + 1]) == 0)
	{
	  len = size_env(new_env);
	  new_env = xrealloc(new_env, sizeof(*new_env) * (len + 2));
	  new_env[len] = av[i + 1];
	  new_env[len + 1] = 0;
	}
      while (strcmp(av[1], "-i") == 0 && av[i])
	{
	  if (check_equal(av[i]) == 0)
	    i++;
	  else
	    exec_in_builtin(&av[i], recup_shell(0), new_env);
	  i++;
	}
      while (strcmp(av[1], "env") == 0 && av[i])
	{
	  if (check_equal(av[i]) == 0)
	    {
	      new_env = copy(env, new_env);
	      len = strlen_equal(av[i]);
	      
	    }
	  exec_in_builtin(av[i], recup_shell(0), 0);
	  i++;
	}
      i++;
      return (0);
    }
}

int	main(int ac, char **av, char **env)
{
  env_funct(&av[1], env);
}
