/*
** aff_motd.c for  in /home/vailla_y/Projet/42shtest/src
**
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
**
** Started on  Wed May 18 11:21:27 2011 Vaillant Yann
** Last update Sun May 22 12:50:19 2011 Vaillant Yann
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
      if (test_balise_motd(ascii, "[/ascii]") == 1)
	{
	  free(ascii);
	  return (1);
	}
      printf("%s\n", ascii);
      free(ascii);
    }
  return (0);
}

int	aff_message(int fd)
{
  char *message;
  
  while ((message = get_next_line(fd)) != 0)
    {
      if (test_balise_motd(message, "[/message]") == 1)
	{
	  free (message);
	  return (0);
	}
      message = parse_prompt(message);
      printf("%s\n", message);
      free (message);
    }
  return (0);
}

int	read_motd()
{
  int	fd;
  char	*buf;
  
  if ((fd = open_motd()) == -1)
    return (1);
  while ((buf = get_next_line(fd)) != 0)
    {
      if (test_balise_motd(buf, "[ascii]") == 1)
	aff_ascii(fd);
      if (test_balise_motd(buf, "[message]") == 1)
	aff_message(fd);
      free (buf);
    }
  close(fd);
  return (0);
}

int	aff_motd(t_shell *shell)
{
  t_list_var    *var = shell->variable;
  
  while (var && var->next)
    {
      if (strcmp(var->name, "MOTD") == 0 && strcmp(var->var, "1") == 0)
	{
	  if (read_motd() == 1)
	    return (1);
	  else
	    return (0);
	}
      var = var->next;
    }
  return (0);
}
