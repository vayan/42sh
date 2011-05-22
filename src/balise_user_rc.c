/*
** balise_user_rc.c for  in /home/vailla_y/Projet/42shtest/src
**
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
**
** Started on  Fri May 20 11:08:34 2011 Vaillant Yann
** Last update Sun May 22 02:03:10 2011 timothee maurin
*/

#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "xmalloc.h"
#include "shell.h"
#include "prototype.h"

char    *pseudo_user()
{
  struct passwd *data;
  char *pseudo;

  if ((data = xgetpwuid(getuid())) == NULL)
    return (NULL);
  pseudo = xmalloc(((strlen(data->pw_name) + 1) * sizeof(char)));
  pseudo = strcpy(pseudo, data->pw_name);
  return (pseudo);
}

char    *real_name()
{
  struct passwd *data;
  char *name;

  if ((data = xgetpwuid(getuid())) == NULL)
    return (NULL);
  name = xmalloc(((strlen(data->pw_gecos) + 1) * sizeof(char)));
  strcpy(name, data->pw_gecos);
  return (name);
}

char    *name_host_pc()
{
  char *hostname = xmalloc(80 * sizeof(*hostname));

  if (gethostname(hostname, 80) == -1)
    return (NULL);
  return (hostname);
}
