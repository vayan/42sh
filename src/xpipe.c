/*
** xpipe.c for minishell in /home/maurin_t//minishell/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Mar  1 18:24:04 2011 timothee maurin
** Last update Sat Mar  5 22:48:24 2011 timothee maurin
*/

#include <stdlib.h>
#include <unistd.h>

int	*xpipe(int *tab)
{
  if (pipe(tab) == -1)
    {
      write(2, "error", 5);
      exit(42);
    }
  return (tab);
}
