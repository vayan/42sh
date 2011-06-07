/*
** my_strcpy.c for my_strcpy in /home/maurin_t//afs/rendu/piscine/Jour_06
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Mon Oct 11 09:39:26 2010 timothee maurin
** Last update Tue Jun  7 16:35:26 2011 timothee maurin
*/

#include <string.h>

char	*my_strcpy(char *dest, char *src)
{
  int	n;

  n = 0;
  dest[n] = src[n];
  while (src[n] != '\0')
    {
      n = n + 1;
      dest[n] = src[n];
    }
  return (dest);
}

char	*my_strcpy_buf(char *dest, char *src)
{
  int	n;

  n = strlen(src);
  dest[n] = src[n];
  while (n > 0)
    {
      n = n - 1;
      dest[n] = src[n];
    }
  return (dest);
}
