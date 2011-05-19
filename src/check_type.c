/*
** check_type.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue May 17 14:19:03 2011 maxime constantinian
** Last update Thu May 19 19:58:15 2011 maxime constantinian
*/

#include	<unistd.h>
#include	"shell.h"
#include	"prototype.h"

int		check_if_builtin(char *name)
{
  if (strcmp(name, "env") == 0 || strcmp(name, "setenv") == 0
      || strcmp(name, "unsetenv") == 0 || strcmp(name, "echo") == 0
      || strcmp(name, "exit") == 0 || strcmp(name, "cd") == 0)
    return (1);
  return (0);
}

int		check_if_alias(char *name, t_list_var *variable)
{
  while (variable)
    {
      if (strcmp(name, variable->name) == 0)
	return (1);
      variable = variable->next;
    }
  return (0);
}

int		check_type(char *name, t_shell *shell)
{
  if (check_if_alias(name, shell->alias))
    return (1);
  if (check_if_builtin(name))
    return (2);
  if (recup_hach(shell->tab_hach, name))
    return (3);
  if (access(name, F_OK) != -1)
    return (4);
  return (0);
}
