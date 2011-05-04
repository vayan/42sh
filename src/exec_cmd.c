/*
** exec_cmd.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 02:16:59 2011 maxime constantinian
** Last update Wed May  4 15:50:24 2011 maxime constantinian
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/time.h>
#include	<sys/resource.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	"shell.h"
#include	"parseur.h"
#include	"prototype.h"

void		exec_fonction(t_commande *cmd, t_shell *shell)
{
  if (execve(recup_hach(shell->tab_hach, cmd->cmd[0]),
  	     cmd->cmd, shell->env) == -1)
    exit(fprintf(stderr, "42sh: execve failed.\n"));
}

void		pipe_fonction(t_commande *cmd, t_shell *shell)
{
  pid_t		returnfork;
  int		tab[2];

  xpipe(tab);
  if ((returnfork = xfork()) == 0)
    {
      close(tab[0]);
      xdup2(tab[1], 1);
      exec_type_cmd(cmd->next[0], shell);
    }
  else
    {
      close(tab[1]);
      xdup2(tab[0], 0);
      exec_type_cmd(cmd->next[1], shell);
    }
}

void		exec_type_cmd(t_commande *cmd, t_shell *shell)
{

  if (cmd->type == OP_PIP)
    pipe_fonction(cmd, shell);
  if (cmd->type == CMD)
    exec_fonction(cmd, shell);
}

void		exec_cmd(t_shell *shell)
{
  pid_t		returnfork;
  int		status;
  int		i = 0;

  if (shell->commande->cmd->type == OP_SEP)
    while (shell->commande->cmd->next[i])
      {
	if ((returnfork = xfork()))
	  while (returnfork != wait4(returnfork, &status, WNOHANG, 0))
	    usleep(100);
	else
	  exec_type_cmd(shell->commande->cmd->next[i], shell);
	i++;
      }
  else
    if ((returnfork = xfork()))
      while (returnfork != wait4(returnfork, &status, WNOHANG, 0))
	usleep(100);
    else
      exec_type_cmd(shell->commande->cmd, shell);
}
