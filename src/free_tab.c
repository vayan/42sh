/*
** free_tab.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat May 21 22:06:36 2011 timothee maurin
** Last update Sun Jun 12 16:06:12 2011 maxime constantinian
*/

#include <stdlib.h>

int	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
  return (0);
}
