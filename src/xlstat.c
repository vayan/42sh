/*
** xlstat.c for xlstat in /home/maurin_t//prog_unix
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat Dec 18 12:51:31 2010 timothee maurin
** Last update Sun May 22 02:05:19 2011 timothee maurin
*/

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int	xlstat(char *file, struct stat *sb)
{
  if (lstat(file, sb) == -1)
    return (0);
  else
    return (1);
}
