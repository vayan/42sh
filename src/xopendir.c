/*
** xopendir.c for xopendir in /home/maurin_t//prog_unix
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat Dec 18 12:20:22 2010 timothee maurin
** Last update Mon Jan  3 10:24:26 2011 timothee maurin
*/

#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

DIR	*xopendir(char *dir)
{
  DIR	*dirp;

  dirp = opendir(dir);
  if (dirp == '\0')
    {
      exit(42);
    }
  return (dirp);
}
