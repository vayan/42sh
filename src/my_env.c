/*
** my_env.c for my_env.c in /home/pugeat_j/
** 
** Made by justin pugeat
** Login   <pugeat_j@epitech.net>
** 
** Started on  Tue Apr 19 17:04:07 2011 justin pugeat
** Last update Tue Apr 26 18:45:10 2011 justin pugeat
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "shell.h"
#include "xmalloc.h"
#include "header.h"

int	my_strcmp2(char *s1, char *s2)
{
  int	a;

  a = 0;
  while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0')
    {
      a++;
      if (s1[a] == '=' || s1[a] == '\0' && s2[a] == '=')
        return (1);
    }
  return (0);
}

char	*my_get_env(char *to_find, char **env)
{
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (env[i])
    {
      if (my_strcmp2(to_find, env[i]))
	{
	  while (env[i][j] != '=')
	    j++;
	  return (my_strcopynalloc(&env[i][++j]));
	}
      i++;
    }
  return (0);
}
