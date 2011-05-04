/*
** isfile.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sun Apr 10 17:51:08 2011 maxime constantinian
** Last update Wed May  4 03:07:02 2011 maxime constantinian
*/

#include	<sys/stat.h>
#include	<stdio.h>

int		isfile(char *str)
{
  struct stat	buf;

  if (lstat(str, &buf) == -1)
    {
      fprintf(stderr, "42sh: lstat failded\n");
      return (0);
    }
  if (S_ISREG(buf.st_mode))
    return (1);
  else
    return (0);
}
