/*
** free_graph_parseur.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sun May 22 04:00:14 2011 maxime constantinian
** Last update Sun May 22 04:23:35 2011 maxime constantinian
*/

#include	<stdlib.h>
#include	"shell.h"
#include	"prototype.h"
#include	"parseur.h"

void		free_graph_maillon(t_commande *cmd)
{
  if (cmd == 0)
    return ;
  if (cmd->next && cmd->next[0])
    free_graph_maillon(cmd->next[0]);
  if (cmd->next && cmd->next[1])
    free_graph_maillon(cmd->next[1]);
  if (cmd->cmd)
    free_tab(cmd->cmd);
  if (cmd->next)
    free(cmd->next);
  free(cmd);
}

void		free_graph_parseur(t_commande *cmd)
{
  int		i = 0;

  if (cmd && cmd->type == OP_SEP)
    {
      while (cmd->next[i])
	{
	  if (cmd->next[i])
	    free_graph_maillon(cmd->next[i]);
	  i++;
	}
      if (cmd->cmd)
	free_tab(cmd->cmd);
      free(cmd->next);
      free(cmd);
    }
  else
    free_graph_maillon(cmd);
}
