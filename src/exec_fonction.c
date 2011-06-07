/*
** exec_fonction.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sat May 21 23:22:37 2011 maxime constantinian
** Last update Tue Jun  7 17:07:40 2011 timothee maurin
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include	"shell.h"
#include	"prototype.h"
#include	"parseur.h"

int		exec_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int		type = 0;
  char		*str = 0;

  if (cmd->cmd && (type = check_type(cmd->cmd[0], shell)) == 0)
    if (cmd->cmd[0] != 0)
      return (fprintf(stderr, "42sh: %s: command not found.\n",
                      cmd->cmd[0]) * 0 + 127);
    else
      return (fprintf(stderr, "42sh: Invalid null commande.\n") * 0 - 1);
  if (type == 3)
    str = recup_hach(shell->tab_hach, cmd->cmd[0]);
  if (type == 4)
    str = cmd->cmd[0];
  if (type == 3 || type == 4)
    return (exec_with_fork(cmd, shell, tab, str));
  if (type == 2)
    return (exec_builtin(cmd, shell, tab));
  return (1);
}

void		and_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int		ret;

  ret = exec_type_cmd(cmd->next[0], shell, tab);
  if (ret == 0)
    {
      tab[0] = 0;
      tab[1] = 0;
      exec_type_cmd(cmd->next[1], shell, tab);
    }
}

void		or_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int	ret;

  ret = exec_type_cmd(cmd->next[0], shell, tab);
  if (ret != 0)
    {
      tab[0] = 0;
      tab[1] = 0;
      exec_type_cmd(cmd->next[1], shell, tab);
    }
}

int		pipe_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int		tab_pipe[2];
  int		tab_ret[2];
  int		ret;

  xpipe(tab_pipe);
  tab_ret[0] = tab[0];
  tab_ret[1] = tab[1];
  if (tab[1] == 0)
    tab_ret[1] = tab_pipe[1];
  else
    {
      xclose(tab_pipe[0]);
      xclose(tab_pipe[1]);
      fprintf(stderr, "42sh: Ambiguous redirect.\n");
    }
  ret = exec_type_cmd(cmd->next[0], shell, tab_ret);
  if (ret != -1)
    {
      tab_ret[0] = tab_pipe[0];
      tab_ret[1] = 0;
      return (exec_type_cmd(cmd->next[1], shell, tab_ret));
    }
  return (ret);
}

int		exec_type_cmd(t_commande *cmd, t_shell *shell, int *tab)
{
  int		ret = 0;

  if (cmd->type == OP_PIP)
    ret = pipe_fonction(cmd, shell, tab);
  if (cmd->type == OP_AND)
    and_fonction(cmd, shell, tab);
  if (cmd->type == OP_OR)
    or_fonction(cmd, shell, tab);
  if (cmd->type == CMD)
    ret = exec_fonction(cmd, shell, tab);
  if (cmd->type == OP_SRR)
    ret = srd_fonction(cmd, shell, tab);
  if (cmd->type == OP_DRR)
    ret = drd_fonction(cmd, shell, tab);
  if (cmd->type == OP_DRL)
    ret = drl_fonction(cmd, shell, tab);
  if (cmd->type == OP_SRL)
    ret = srl_fonction(cmd, shell, tab);
  return (ret);
}
