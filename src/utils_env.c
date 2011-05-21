/*
** utils_env.c for  in /home/vailla_y//Projet/42sh/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Wed May  4 15:42:43 2011 yann vaillant
** Last update Sat May 21 18:19:07 2011 Vaillant Yann
*/

#include        <string.h>
#include        <stdlib.h>
#include        <stdio.h>
#include        "shell.h"
#include        "graph.h"
#include        "xmalloc.h"

char    *get_name_env(char *value)
{
  int   i = 0;
  char *retour = xmalloc((strlen(value) + 1) * sizeof(*retour));

  while (value[i] != '=')
    {
      retour[i] = value[i];
      i++;
    }
  return (retour);
}

int     go_end_env(char **env)
{
  int   x = 0;
  
  if (env)
    while (env[x])
      x++;
  return (x);
}
