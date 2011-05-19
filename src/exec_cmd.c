/*
** exec_cmd.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 02:16:59 2011 maxime constantinian
<<<<<<< local
** Last update Thu May 19 18:30:05 2011 maxime constantinian
=======
** Last update Tue May 17 16:34:49 2011 justin pugeat
>>>>>>> other
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/time.h>
#include	<sys/resource.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<errno.h>
#include	"shell.h"
#include	"parseur.h"
#include	"prototype.h"

<<<<<<< local
/* void		exec_in_builtin(char **cmd, t_shell *shell, char **env) */
/* { */
/*   if (execve(recup_hach(shell->tab_hach, cmd[0]), */
/*   	     cmd, env) == -1) */
/*     exit(fprintf(stderr, "42sh: execve failed.\n")); */
/* } */

void		fils_fonction(t_commande *cmd, t_shell *shell,
			       int *tab, char *str)
=======
void		exec_in_builtin(t_commande *cmd, t_shell *shell, char **env)
>>>>>>> other
{
<<<<<<< local
  if (tab && tab[1])
    xdup2(tab[1], 1);
  if (tab && tab[0])
    xdup2(tab[0], 0);
  if (execve(str, cmd->cmd, shell->env) == -1)
=======
  if (execve(recup_hach(shell->tab_hach, cmd->cmd[0]),
  	     cmd->cmd, env) == -1)
>>>>>>> other
    exit(fprintf(stderr, "42sh: execve failed.\n"));
}

int		return_good_return_value(int stat_val)
{
<<<<<<< local
  if (WIFEXITED(stat_val))
    return (WEXITSTATUS(stat_val));
  return (stat_val);
=======
  if (execve(recup_hach(shell->tab_hach, cmd->cmd[0]), cmd->cmd, shell->env) == -1)
    exit(fprintf(stderr, "42sh: execve failed.\n"));
>>>>>>> other
}

int		exec_with_fork(t_commande *cmd, t_shell *shell,
			       int *tab, char *str)
{
  int		returnfork;
  int		status = 0;
  
  if ((returnfork = xfork()))
    {
      if (tab)
	{
	  if (tab[0] != 0)
	    close(tab[0]);
	  if (tab[1] != 0)
	    close(tab[1]);
	}
      while (returnfork != wait4(returnfork, &status, WNOHANG, 0))
	usleep(100);
      return (return_good_return_value(status));
    }
  else
    fils_fonction(cmd, shell, tab, str);
}

int		exec_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int		type;
  char		*str = 0;

  type = check_type(cmd->cmd[0], shell);
  if (type == 3)
    str = recup_hach(shell->tab_hach, cmd->cmd[0]);
  if (type == 4)
    str = cmd->cmd[0];
  if (type == 3 || type == 4)
    return (exec_with_fork(cmd, shell, tab, str));
  if (type == 2)
    exec_builtin(cmd, shell, tab);
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
  int		ret;

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
  if (tab && tab[1] == 0)
    {
      tab_ret[0] = tab[0];
      tab_ret[1] = tab_pipe[1];
    }
  else
    {
      tab_ret[0] = 0;
      tab_ret[1] = tab_pipe[1];
    }
  ret = exec_type_cmd(cmd->next[0], shell, tab_ret);
  if (ret == 0);
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
    srd_fonction(cmd, shell, tab);
  if (cmd->type == OP_DRR)
    drd_fonction(cmd, shell, tab);
  if (cmd->type == OP_DRL)
    drl_fonction(cmd, shell, tab);
  if (cmd->type == OP_SRL)
    srl_fonction(cmd, shell, tab);
  return (ret);
}

void		exec_cmd(t_shell *shell)
{
  int		i;
  int		tab[2];

  i = 0;
  tab[0] = 0;
  tab[1] = 0;
  if (shell->commande->cmd->type == OP_SEP)
    {
      while (shell->commande->cmd->next[i])
	{
	  exec_type_cmd(shell->commande->cmd->next[i], shell, tab);
	  i++;
	}
    }
  else
    exec_type_cmd(shell->commande->cmd, shell, tab);
}
