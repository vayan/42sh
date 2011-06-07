/*
** exec_cmd.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 02:16:59 2011 maxime constantinian
** Last update Tue Jun  7 17:05:54 2011 timothee maurin
*/

#include	<unistd.h>
#include	<string.h>
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
  char		**env_sauve = shell->env;
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
    exit(fprintf(stderr, "42sh: execve failed : %s.\n", strerror(errno)));
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
  int		ret = -1;

  if (WIFSIGNALED(stat_val))
    aff_warning(WTERMSIG(stat_val));
  if (WIFEXITED(stat_val))
    ret = WEXITSTATUS(stat_val);
  if (ret == -1)
    ret = stat_val;
  update_var_with_ret(ret);
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
  free_graph_parseur(shell->commande->cmd);
}
