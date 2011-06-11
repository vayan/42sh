/*
** check_type.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue May 17 14:19:03 2011 maxime constantinian
** Last update Sat Jun 11 19:43:08 2011 maxime constantinian
*/

#include	<string.h>
#include	<unistd.h>
#include	"shell.h"
#include	"prototype.h"

int		check_if_builtin(char *name)
{
  if (strcmp(name, "env") == 0 || strcmp(name, "setenv") == 0
      || strcmp(name, "unsetenv") == 0 || strcmp(name, "echo") == 0
      || strcmp(name, "exit") == 0 || strcmp(name, "cd") == 0
      || strcmp(name, "set") == 0 || strcmp(name, "unset") == 0
      || strcmp(name, "alias") == 0 || strcmp(name, "unalias") == 0)
    return (1);
  return (0);
}

int		check_if_alias(char *name, t_list_var *alias)
{
  while (alias && alias->next != 0 && strcmp(name, alias->name) != 0)
    alias = alias->next;
  if (alias == 0 || alias->next == 0)
    return (0);
  return (1);
}

int		check_type(char *name, t_shell *shell)
{
  if (name)
    {
      if (check_if_builtin(name))
	return (2);
      if (recup_hach(shell->tab_hach, name))
	return (3);
      if ((name[0] == '.' || name[0] == '/') && access(name, F_OK) != -1)
	return (4);
    }
  return (0);
}
