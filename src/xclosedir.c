/*
** xclosedir.c for  in /home/vailla_y/Projet/42shtest
** 
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
** 
** Started on  Sun May 22 16:27:52 2011 Vaillant Yann
** Last update Sun May 22 16:31:00 2011 Vaillant Yann
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int	xclosedir(DIR *dirp)
{
  if (closedir(dirp) == -1)
    {
      fprintf(stderr, "42sh: Closedir : %s\n", strerror(errno));
      return (-1);
    }
  return (0);
}
