/*
** exec_fork.c for  in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sat May 21 23:26:50 2011 maxime constantinian
** Last update Sun May 22 16:53:26 2011 maxime constantinian
*/

#include	<string.h>
#include	<unistd.h>
#include	<sys/wait.h>
#include	"shell.h"
#include	"prototype.h"

/* void		modif_cmd(t_commande *cmd, t_shell *shell) */
/* { */
/*   int		i; */
/*   int		j; */

/*   i = 1; */
/*   while (cmd->cmd[i]) */
/*     { */
/*       i++; */
/*     } */
/* } */

int		exec_with_fork(t_commande *cmd, t_shell *shell,
                               int *tab, char *str)
{
  int		returnfork;
  int		status = 0;

  //modif_cmd(cmd, shell);
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

int		re_builtin(t_commande *cmd, t_shell *shell, int *tab_built)
{
  int		ret = 0;

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
    ret = my_set(cmd->cmd, tab_built);
  if (strcmp(cmd->cmd[0], "unset") == 0)
    ret = my_unset(cmd->cmd);
  update_var_with_ret(ret);
  return (ret);
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
  ret = re_builtin(cmd, shell, tab_built);
  if (tab[0] != 0 && tab[0] != 1)
    close(tab[0]);
  if (tab[1] != 1 && tab[1] != 0)
    close(tab[1]);
  return (ret);
}
