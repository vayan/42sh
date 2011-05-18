/*
** aff_motd.c for  in /home/vailla_y/Projet/42shtest/src
**
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
**
** Started on  Wed May 18 11:21:27 2011 Vaillant Yann
** Last update Wed May 18 12:11:08 2011 Vaillant Yann
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <stdio.h>
#include "xmalloc.h"
#include "get_next_line.h"

int	test_balise(char *str, char *balise)
{
  if (strcmp(str, balise) == 0)
    return (1);
  return (0);
}

char    *path_motd()
{
  struct passwd *home;
  char *path;

  if ((home = xgetpwuid(getuid())) == NULL)
    return (NULL);
  path = xmalloc((strlen(home->pw_dir)
                  + strlen("/.42motd") + 1) * sizeof(char));
  path = strcat(path, home->pw_dir);
  path = strcat(path, "/.42motd");
  return (path);
}

int	aff_ascii(int fd)
{
  char *ascii;

  while ((ascii = get_next_line(fd)) != 0)
    {
      if (test_balise(ascii, "[/ascii]") == 1)
	return (1);
      printf("%s\n", ascii);
    }
  return (0);
}

int	aff_message(int fd)
{
  char *message;

  while ((message = get_next_line(fd)) != 0)
    {
      if (test_balise(message, "[/message]") == 1)
	return (0);
      printf("%s\n", message);
    }
  return (0);
}

int	read_motd()
{
  int	fd;
  char	*buf;

  if ((fd = open(path_motd(), O_RDONLY)) == -1)
    return (1);
  while ((buf = get_next_line(fd)) != 0)
    {
      if (test_balise(buf, "[ascii]") == 1)
	aff_ascii(fd);
      if (test_balise(buf, "[message]") == 1)
	aff_message(fd);
    }
  close(fd);
  return (0);
}
