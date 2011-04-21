/*
** get_touche.c for 42sh  in /home/vailla_y//Projet/42sh/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Apr 21 17:41:38 2011 yann vaillant
** Last update Thu Apr 21 18:10:02 2011 yann vaillant
*/

#include <unistd.h>

char *get_touche()
{
  int	ret;
  char *touche = xmalloc(6 * sizeof(char));

  ret = read(0,touche, 5);
  touche[ret] = '\0';
  return (touche);
}
