/*
** my_pwd.c for my_pwd in /home/maurin_t/
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sun Jan  2 19:38:21 2011 timothee maurin
** Last update Mon Jan  3 16:45:42 2011 timothee maurin
*/

#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "concat.h"
#include "xopendir.h"
#include "xlstat.h"

void	funct_eco(DIR *dirp, char *pwd)
{
  free(dirp);
  chdir(pwd);
}

char	*funct_concat(char *pwd, char *name)
{
  char	*tmp;

  tmp = concat(pwd, name);
  free(pwd);
  return (tmp);
}

char		*my_pwd(char *pwd)
{
  struct stat	searched;
  struct stat	current;
  struct dirent *entry;
  DIR		*dirp;

  xlstat(".", &searched);
  chdir("..");
  dirp = xopendir(".");
  entry = readdir(dirp);
  xlstat(entry->d_name, &current);
  while (entry != 0 && (current.st_ino != searched.st_ino
			   || current.st_dev != searched.st_dev))
    {
      entry = readdir(dirp);
      xlstat(entry->d_name, &current);
    }
  xlstat(".", &current);
  if (current.st_ino != searched.st_ino
      || current.st_dev != searched.st_dev)
    {
      pwd = my_pwd(pwd);
      pwd = funct_concat(pwd, entry->d_name);
    }
  funct_eco(dirp, pwd);
  return (pwd);
}
