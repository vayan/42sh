/*
** check_motd.c for  in /home/vailla_y/Projet/42shtest
** 
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
** 
** Started on  Sun May 22 12:48:14 2011 Vaillant Yann
** Last update Sun May 22 12:49:18 2011 Vaillant Yann
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <stdio.h>
#include "xmalloc.h"
#include "get_next_line.h"
#include "shell.h"
#include "prototype.h"

int     open_motd()
{
  int   fd;
  int   fd_verif;
  char  *path = path_motd();

  if ((fd_verif = open(path, O_RDONLY)) == -1)
    {
      free (path);
      return (-1);
    }
  if (check_good_balise(fd_verif) == -1)
    {
      free (path);
      return (-1);
    }
  close(fd_verif);
  if ((fd = open(path, O_RDONLY)) == -1)
    {
      free (path);
      return (-1);
    }
  free (path);
  return (fd);
}

int     check_good_balise(int fd)
{
  char  *buf;
  int   open_asc = 0;
  int   close_asc = 0;
  int   open_msg = 0;
  int   close_msg = 0;

  while ((buf = get_next_line(fd)) != 0)
    {
      if (test_balise_motd(buf, "[ascii]") == 1)
        open_asc++;
      if (test_balise_motd(buf, "[/ascii]") == 1)
        close_asc++;
      if (test_balise_motd(buf, "[message]") == 1)
        open_msg++;
      if (test_balise_motd(buf, "[/message]") == 1)
        close_msg++;
      free(buf);
    }
  if ((open_asc == close_asc) && (open_msg == close_msg))
    return (0);
  else
    return (-1);
}

int     test_balise_motd(char *str, char *balise)
{
  if (strcmp(str, balise) == 0)
    return (1);
  return (0);
}
