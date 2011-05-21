/*
** exec_cmd.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 02:16:59 2011 maxime constantinian
** Last update Sat May 21 18:28:05 2011 maxime constantinian
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

int		exec_in_builtin(char **cmdeuh, t_shell *shell,
				char **env, int *tab)
{
  int		type = 0;
  int		ret = 0;
  char		*str = 0;
  char		**env_sauve;
  t_commande	cmd;

  cmd.next = 0;
  cmd.cmd = cmdeuh;
  if (tab[1] == 1)
    tab[1] = 0;
  if (cmd.cmd && (type = check_type(cmd.cmd[0], shell)) == 0)
    if (cmd.cmd[0] != 0)
      return (fprintf(stderr, "42sh: %s: command not found.\n",
		      cmd.cmd[0]) * 0 + 127);
  if (type == 3)
    str = recup_hach(shell->tab_hach, cmd.cmd[0]);
  if (type == 4)
    str = cmd.cmd[0];
  env_sauve = shell->env;
  shell->env = env;
  if (type == 3 || type == 4)
    ret = exec_with_fork(&cmd, shell, tab, str);
  if (type == 2)
    ret = exec_builtin(&cmd, shell, tab);
  shell->env = env_sauve;
  return (ret);
}

void		fils_fonction(t_commande *cmd, t_shell *shell,
			      int *tab, char *str)
{
  if (tab && tab[1])
    xdup2(tab[1], 1);
  if (tab && tab[0])
    xdup2(tab[0], 0);
  if (execve(str, cmd->cmd, shell->env) == -1)
    exit(fprintf(stderr, "42sh: execve failed : %s.\n", strerror(errno));
}

void		aff_warning(int stat_val)
{
  if (stat_val == SIGSEGV)
    fprintf(stderr, "Segmentation fault!\n");
  if (stat_val == SIGFPE)
    fprintf(stderr, "Floating exception!\n");
  if (stat_val == SIGUSR1)
    fprintf(stderr, "User signal 1!\n");
  if (stat_val == SIGUSR2)
    fprintf(stderr, "User signal 2!\n");
  if (stat_val == SIGSTKFLT)
    fprintf(stderr, "Stack fault!\n");
  if (stat_val == SIGPIPE)
    fprintf(stderr, "Broken pipe!\n");
}

int		return_good_return_value(int stat_val)
{
  if (WIFSIGNALED(stat_val))
    aff_warning(WTERMSIG(stat_val));
  if (WIFEXITED(stat_val))
    return (WEXITSTATUS(stat_val));
  return (stat_val);
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
  return (1);
}

int		exec_builtin(t_commande *cmd, t_shell *shell, int *tab)
{
  int		tab_built[2];
  int		ret = 0;

  tab_built[0] = 0;
  if (tab[0] != 0)
    tab_built[0] = tab[0];
  tab_built[1] = 1;
  if (tab[1] != 0)
    tab_built[1] = tab[1];
  if (strcmp(cmd->cmd[0], "cd") == 0)
    ret = exec_cd(cmd->cmd, shell->env, tab_built);
  if (strcmp(cmd->cmd[0], "setenv") == 0)
    ret = my_setenv(cmd->cmd, shell->env, tab_built);
  if (strcmp(cmd->cmd[0], "env") == 0)
    ret = env_funct(cmd->cmd, shell->env, tab_built);
  if (strcmp(cmd->cmd[0], "echo") == 0)
    ret = my_echo(cmd->cmd, shell->env, tab_built);
  if (strcmp(cmd->cmd[0], "exit") == 0)
    ret = exit_func(cmd->cmd, shell->env);
  if (strcmp(cmd->cmd[0], "set") == 0)
    ret = my_set(cmd->cmd, shell->env, tab_built);
  if (tab[0] != 0 && tab[0] != 1)
    close(tab[0]);
  if (tab[1] != 1 && tab[1] != 0)
    close(tab[1]);
  return (ret);
}

int		exec_fonction(t_commande *cmd, t_shell *shell, int *tab)
{
  int		type;
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
  tab_ret[0] = tab[0];
  tab_ret[1] = tab[1];
  if (tab[1] == 0)
    tab_ret[1] = tab_pipe[1];
  else
    {
      close(tab_pipe[1]);
      close(tab_pipe[2]);
      fprintf(stderr, "42sh: Ambiguous redirect.\n");
    }
  ret = exec_type_cmd(cmd->next[0], shell, tab_ret);
  if (ret == 0)
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
