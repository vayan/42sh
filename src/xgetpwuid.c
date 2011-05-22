/*
** xgetpwuid.c for  in /home/vailla_y/Projet/42shtest/src
** 
** Made by Vaillant Yann
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue May 17 17:14:49 2011 Vaillant Yann
** Last update Sun May 22 22:04:35 2011 timothee maurin
*/

#include <string.h>
#include <sys/types.h>
#include <pwd.h>

struct passwd  *xgetpwuid(int uid)
{
  struct passwd *get;

  if ((get = getpwuid(uid)) == NULL)
    return (NULL);
  return (get);
}
