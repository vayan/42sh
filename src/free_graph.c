/*
** free_graph.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Mon Apr 11 14:47:49 2011 maxime constantinian
** Last update Sun May 22 04:34:52 2011 timothee maurin
*/

#include	<stdlib.h>
#include	"shell.h"
#include	"graph.h"

void		free_graph(t_hach_bin *tab)
{
  int		i;

  i = 0;
  if (tab == NULL)
    return ;
  else
    {
      while (tab->next && i < 94)
	{
	  if (tab->next[i])
	    free_graph(tab->next[i]);
	  i++;
	}
      if (tab->path)
	{
	  free(tab->path);
	  tab->path = 0;
	}
      if (tab->next)
	free(tab->next);
      free(tab);
    }
}
