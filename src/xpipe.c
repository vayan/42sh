/*
** xpipe.c for minishell in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 18:24:04 2011 timothee maurin
** Last update Wed May  4 16:06:01 2011 maxime constantinian
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	*xpipe(int *tab)
{
  if (pipe(tab) == -1)
    {
      fprintf(stderr, "42sh: Pipre failed\n");
      return (0);
    }
  return (tab);
}
