/*
** xclosedir.c for  in /home/vailla_y/Projet/42shtest
** 
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
** 
** Started on  Sun May 22 16:27:52 2011 Vaillant Yann
** Last update Sun Jun 12 18:22:12 2011 timothee maurin
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
    return (-1);
  return (0);
}
