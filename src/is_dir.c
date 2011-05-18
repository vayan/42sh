/*
** is_dir.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May 18 17:54:30 2011 timothee maurin
** Last update Wed May 18 18:03:35 2011 timothee maurin
*/

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "shell.h"
#include "prototype.h"

int		is_dir(char *buf, char *buf2, int pos, int begin)
{
  struct stat   sb;
  char          *tmp;

  while (buf[pos] != '/' && pos > 0)
    pos--;
  tmp = xmalloc((pos - begin + 2 + strlen(buf2)) * sizeof(*tmp));
  if (pos - begin > 0)
    strncpy(tmp, &(buf[begin + 1]), pos - begin);
  strcat(tmp, buf2);
  xlstat(tmp, &sb);
  if (S_ISDIR(sb.st_mode))
    xwrite(0, "/", 1);
  else if (!(access(tmp, X_OK)))
    xwrite(0, "*", 1);
  free(tmp);
  return (0);
}
