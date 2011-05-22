/*
** parse_rc.c for  in /home/vailla_y//Projet/42sh/src
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Wed May  4 16:59:09 2011 yann vaillant
** Last update Sun May 22 02:01:31 2011 timothee maurin
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include "shell.h"
#include "get_next_line.h"
#include "prototype.h"

int	check_if_exist_in_list(char *name_var, t_list_var *list_var)
{
  t_list_var *temp = list_var;

  while (temp && temp->next != NULL && name_var)
    {
      if (strcmp(name_var, temp->name) == 0)
	return (1);
      temp = temp->next;
    }
  return (0);
}

void	init_list_var(t_list_var **list_var, t_list_var **buffer,
		      t_list_var **alias, t_shell **shell)
{
  (*shell)->variable = xmalloc(sizeof(t_list_var));
  (*shell)->alias = xmalloc(sizeof(t_list_var));
  *list_var = (*shell)->variable;
  *buffer = (*shell)->variable;
  (*list_var)->next = 0;
  *alias = (*shell)->alias;
  (*alias)->next = 0;
}

void	parse_ligne(int fd, t_shell *shell)
{
  char	     **name_var;
  char	     *toparse;
  t_list_var *list_var;
  t_list_var *buffer;
  t_list_var *alias;
  t_list_var *alias_buf;

  init_list_var(&list_var, &buffer, &alias, &shell);
  alias_buf = shell->alias;
  while ((toparse = get_next_line(fd)) != 0)
    {
      name_var = str_to_wordtab_parse_rc(toparse);
      if (name_var[0])
	{
	  test_set(name_var, &buffer, &list_var);
	  test_alias(name_var, &alias_buf, &alias);
	  test_unset(name_var, &buffer);
	}
      free(toparse);
      free_tab(name_var);
    }
}

int	parse_rc(t_shell *shell)
{
  int fd = 0;
  char *path;

  if ((path = path_file()) == NULL)
    return (1);
  fd = open(path, O_RDONLY);
  if (fd != -1)
    {
      parse_ligne(fd, shell);
      close(fd);
    }
  free(path);
  return (0);
}
