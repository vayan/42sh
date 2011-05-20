/*
** balise_term.c for  in /home/vailla_y//Projet/42shtest
**
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
**
** Started on  Wed May 18 17:00:01 2011 yann vaillant
** Last update Fri May 20 11:09:19 2011 Vaillant Yann
*/

#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "xmalloc.h"

char	*current_folder()
{
  char *path = xmalloc(80 * sizeof(*path));
  char *current = xmalloc(80 * sizeof(*current));
  int	i = 0;
  int	x;

  if (getcwd(path, 80) == NULL)
    return (NULL);
  x = strlen(path)-1;
  while (path[x-1] != '/')
    x--;
  while (path[x])
    current[i++] = path[x++];
  free(path);
  return (current);
}

char	*folder_to_home()
{
  char *path = xmalloc(80 * sizeof(*path));

  if (getcwd(path, 80) == NULL)
    return (NULL);
  return (path);
}

char	*current_shell()
{
  struct passwd *data;
  char *shell;

  if ((data = xgetpwuid(getuid())) == NULL)
    return (NULL);
  shell = xmalloc(((strlen(data->pw_shell) + 1) * sizeof(char)));
  shell = strcpy(shell, data->pw_shell);
  return (shell);
}
