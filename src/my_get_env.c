/*
** my_env.c for my_env.c in /home/pugeat_j/
** 
** Made by justin pugeat
** Login   <pugeat_j@epitech.net>
** 
** Started on  Tue Apr 19 17:04:07 2011 justin pugeat
** Last update Wed May  4 15:39:03 2011 maxime constantinian
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "graph.h"
#include "xmalloc.h"
#include "prototype.h"

int	my_strcmp_equal(char *s1, char *s2)
{
  int	a;

  a = 0;
  while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0')
    {
      a++;
      if ((s1[a] == '=' || s1[a] == '\0') && s2[a] == '=')
        return (1);
    }
  return (0);
}

char	*my_get_env(char *to_find, char **env)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (env[i])
    {
      if (my_strcmp_equal(to_find, env[i]))
	{
	  while (env[i][j] != '=')
	    j++;
	  return (my_strcopynalloc(&env[i][++j]));
	}
      i++;
    }
  return (0);
}
