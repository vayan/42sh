/*
** concat.c for concat in /home/maurin_t//prog_unix
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue Dec 14 17:11:24 2010 timothee maurin
** Last update Sun May 22 02:08:12 2011 timothee maurin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "xmalloc.h"
#include "shell.h"
#include "prototype.h"

char		*concat(char *s1, char *s2)
{
  char		*str;
  int		n;
  int		i;

  i = -1;
  n = 0;
  str = xmalloc((strlen(s1) + strlen(s2) + 2) * sizeof(*str));
  if (!(my_strcmp(s1, ".")) && s1[0] != '\0')
    {
      while (s1[++i] != '\0')
	str[n++] = s1[i];
      if (s1[i - 1] != '/')
	str[n++] = '/';
      i = -1;
      while (s2[++i] != '\0')
	str[n++] = s2[i];
      str[n] = '\0';
      return (str);
    }
  while (s2[++i] != '\0')
    str[n++] = s2[i];
  return (str);
}
