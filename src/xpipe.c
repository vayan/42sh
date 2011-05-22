/*
** xpipe.c for minishell in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 18:24:04 2011 timothee maurin
** Last update Sun May 22 16:10:11 2011 Vaillant Yann
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int	*xpipe(int *tab)
{
  if (pipe(tab) == -1)
    {
      fprintf(stderr, "42sh: Pipe : %s\n", strerror(errno));
      return (0);
    }
  return (tab);
}
