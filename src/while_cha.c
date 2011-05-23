/*
** while_cha.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May 18 19:42:34 2011 timothee maurin
** Last update Mon May 23 09:52:26 2011 maxime constantinian
*/

#include "shell.h"
#include "prototype.h"

char	*while_cha(char *cha, char *str, int *pos, int *i)
{
  int	n;

  n = 0;
  while (cha[n] != '\0' && (!(verif_touche(cha, n)) || cha[n] == 9))
    {
      str = other_cha(cha[n], str, pos, i);
      n++;
    }
  return (str);
}
