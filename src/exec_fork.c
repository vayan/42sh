/*
** exec_fork.c for  in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sat May 21 23:26:50 2011 maxime constantinian
** Last update Tue Jun  7 18:19:51 2011 maxime constantinian
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	<sys/wait.h>
#include	"shell.h"
#include	"prototype.h"

char		*traitement_var(char *str, int *j, t_shell *shell)
{
  char		*bef = my_strcopynalloc_gen(str, *j);
  char		*af ;
  int		i = *j;
  char		*buf;
  char		*tmp;

  while (str[i] && str[i] != ' ' && str[i] != '\n')
    i++;
  af = my_strcopynalloc_gen(&str[i], strlen(&str[i]));
  tmp = my_strcopynalloc_gen(&str[*j + 1], i - *j - 1);
  if ((buf = my_get_env(tmp, shell->env)) == 0)
    if ((buf = my_get_var(tmp, shell->variable)) == 0)
      {
	free(tmp);
	free(af);
	free(bef);
	return (str + (*j = i) * 0);
      }
  tmp = realloc(tmp, strlen(bef) + strlen(buf) + strlen(af) + 1);
  snprintf(tmp, strlen(bef) + strlen(buf) + strlen(af) + 1,
	   "%s%s%s", bef, buf, af);
  *j = strlen(bef) + strlen(buf);
  free(str);
  return (tmp);
}

void		modif_cmd(t_commande *cmd, t_shell *shell)
{
  int		i;
  int		j = 0;

  i = 1;
  while (cmd->cmd[i])
    {
      j = 0;
      while (cmd->cmd[i][j])
	{
	  while (cmd->cmd[i][j] && cmd->cmd[i][j] != '$')
	    j++;
	  if (cmd->cmd[i][j] && cmd->cmd[i][j] == '$')
	    cmd->cmd[i] = traitement_var(cmd->cmd[i], &j, shell);
	}
      i++;
    }
}

void		wait_test(int returnfork)
{
  int		status = 0;

  if (xfork(0) == 0)
    {
      while (returnfork != wait4(returnfork, &status, WNOWAIT, 0))
	usleep(100);
      exit(42);
    }
}

int		exec_with_fork(t_commande *cmd, t_shell *shell,
                               int *tab, char *str)
{
  int		returnfork;
  int		status = 0;

  modif_cmd(cmd, shell);
  if ((returnfork = xfork(0)))
    {
      if (tab)
	{
	  if (tab[0] != 0)
	    xclose(tab[0]);
	  if (tab[1] != 0)
	    xclose(tab[1]);
	}
      if (tab[1] == 0 || xpipe(&tab[1], 1))
	{
	  while (returnfork != wait4(returnfork, &status, WNOHANG, 0))
	    usleep(100);
	  return (xfork(1) * 0 + return_good_return_value(status));
	}
      return (0);
    }
  else
    fils_fonction(cmd, shell, tab, str);
  return (1);
}

int		re_builtin(t_commande *cmd, t_shell *shell, int *tab_built)
{
  int		ret = 0;

  modif_cmd(cmd, shell);
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
  if (strcmp(cmd->cmd[0], "unsetenv") == 0)
    ret = my_unsetenv(cmd->cmd, shell->env);
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
    xclose(tab[0]);
  if (tab[1] != 1 && tab[1] != 0)
    xclose(tab[1]);
  return (ret);
}
