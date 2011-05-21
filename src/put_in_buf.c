/*
** put_in_buf.c for 42sh in /home/maurin_t/
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue May 17 16:17:00 2011 timothee maurin
** Last update Sat May 21 22:33:46 2011 timothee maurin
*/

#include <string.h>
#include "shell.h"
#include "prototype.h"

void	put_in_buf(char *buf, char *dest, int begin)
{
  int	tmp;
  char	*tmp2;

  tmp = begin;
  while (dest[begin] != '/' && begin > 0 && dest[begin] != ' '\
	 && dest[begin] != ';')
    begin--;
  if (strncmp(buf, &(dest[begin + 1]), strlen(buf)) != 0)
    {
      tmp2 = strdup(&(dest[tmp]));
      my_strcpy(&(dest[begin + strlen(buf) + 1]), tmp2);
      if (begin != 0)
	my_strcpy(&(dest[begin + 1]), buf);
      else
	my_strcpy(&(dest[begin]), buf);
      free(tmp2);
    }
}
