/*
** check_if_have_cmd.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Fri Jun 10 18:28:54 2011 maxime constantinian
** Last update Sat Jun 11 17:57:14 2011 maxime constantinian
*/

#include	"shell.h"
#include	"parseur.h"

int		check_if_have_cmd(t_commande *cmd)
{
  if (cmd == 0)
    return (0);
  if (cmd->type == CMD && cmd->cmd && cmd->cmd[0])
    return (1);
  else if (cmd->type == OP_PIP || cmd->type == OP_AND || cmd->type == OP_OR)
    {
      if (check_if_have_cmd(cmd->next[0]))
	if (check_if_have_cmd(cmd->next[1]))
	  return (1);
      return (0);
    }
  else if (cmd->type != CMD && cmd->type != OP_PIP
	   && cmd->type != OP_AND && cmd->type != OP_OR)
    if (check_if_have_cmd(cmd->next[0]))
      return (1);
  return (0);
}
