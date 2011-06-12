/*
** exec_fonction.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sat May 21 23:22:37 2011 maxime constantinian
** Last update Sun Jun 12 12:40:20 2011 maxime constantinian
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

int		and_fonction(t_commande *cmd, t_shell *shell, int *tab, int i)
{
  int		ret;

  if (check_if_have_cmd(cmd) == 0)
    return (fprintf(stderr, "Invalid null command.\n"));
  ret = exec_type_cmd(cmd->next[0], shell, tab, i);
  tab[0] = 0;
  tab[1] = 0;
  ret = my_getnbr(my_get_var("?", shell->variable));
  return (exec_type_cmd(cmd->next[1], shell, tab, ret));
}

int		or_fonction(t_commande *cmd, t_shell *shell, int *tab, int i)
{
  int		ret;

  if (check_if_have_cmd(cmd) == 0)
    return (fprintf(stderr, "Invalid null command.\n"));
  ret = exec_type_cmd(cmd->next[0], shell, tab, i);
  tab[0] = 0;
  tab[1] = 0;
  ret = my_getnbr(my_get_var("?", shell->variable));
  if (ret != 0)
    ret = 0;
  else
    ret = 1;
  return (exec_type_cmd(cmd->next[1], shell, tab, ret));
}

int		pipe_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int		tab_pipe[2];
  int		tab_ret[2];

  if (check_if_have_cmd(cmd) == 0)
    return (fprintf(stderr, "Invalid null command.\n"));
  xpipe(tab_pipe, 0);
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
  exec_type_cmd(cmd->next[0], shell, tab_ret, 0);
  tab_ret[0] = tab_pipe[0];
  tab_ret[1] = 0;
  return (exec_type_cmd(cmd->next[1], shell, tab_ret, 0));
}

int		exec_type_cmd(t_commande *cmd, t_shell *shell, int *tab, int i)
{
  int		ret = i;
  static int	deja = 0;

  if (i == 0 && cmd->type == OP_PIP)
    ret = pipe_fonction(cmd, shell, tab);
  if (cmd->type == OP_AND)
    ret = and_fonction(cmd, shell, tab, i);
  if (cmd->type == OP_OR)
    ret = or_fonction(cmd, shell, tab, i);
  if (i == 0 && cmd->type == CMD)
    ret = exec_fonction(cmd, shell, tab);
  if ((cmd->type == OP_SRR || cmd->type == OP_DRR
       || cmd->type == OP_SRL || cmd->type == OP_DRL) && deja == 0)
    {
      if (check_if_have_cmd(cmd) == 0)
	return (fprintf(stderr, "Invalid null command.\n"));
      else
	deja = 1;
    }
  else if ((cmd->type == OP_SRR || cmd->type == OP_DRR
	    || cmd->type == OP_SRL || cmd->type == OP_DRL) && deja == 1)
    deja = 0;
  if (i == 0 && cmd->type == OP_SRR)
    ret = srd_fonction(cmd, shell, tab);
  if (i == 0 && cmd->type == OP_DRR)
    ret = drd_fonction(cmd, shell, tab);
  if (i == 0 && cmd->type == OP_DRL)
    ret = drl_fonction(cmd, shell, tab);
  if (i == 0 && cmd->type == OP_SRL)
    ret = srl_fonction(cmd, shell, tab);
  return (ret);
}
