/*
** get_path_rc.c for  in /home/vailla_y/Projet/42shtest/src
**
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
**
** Started on  Tue May 17 17:26:56 2011 Vaillant Yann
** Last update Tue May 17 17:48:12 2011 Vaillant Yann
*/

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include "xmalloc.h"

char    *path_file()
{
  struct passwd *home;
  char *path;

  if ((home = xgetpwuid(getuid())) == NULL)
    return (NULL);
  path = xmalloc((strlen(home->pw_dir)
                  + strlen("/.42shrc") + 1) * sizeof(char));
  path = strcat(path, home->pw_dir);
  path = strcat(path, "/.42shrc");
  return (path);
}
