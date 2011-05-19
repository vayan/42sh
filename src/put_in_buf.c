/*
** put_in_buf.c for 42sh in /home/maurin_t/
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue May 17 16:17:00 2011 timothee maurin
** Last update Thu May 19 14:12:03 2011 timothee maurin
*/

#include <string.h>
#include "shell.h"
#include "prototype.h"

void	put_in_buf(char *buf, char *dest, int begin)
{
  while (dest[begin] != '/' && begin > 0 && dest[begin] != ' '\
	 && dest[begin] != ';')
    begin--;
  if (strncmp(buf, &(dest[begin + 1]), strlen(buf)) != 0)
    {
      my_strcpy(&(dest[begin + strlen(buf) + 1]), &(dest[begin]));
      if (begin != 0)
	my_strcpy(&(dest[begin + 1]), buf);
      else
	my_strcpy(&(dest[begin]), buf);
    }
}
