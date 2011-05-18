/*
** put_in_buf.c for 42sh in /home/maurin_t/
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Tue May 17 16:17:00 2011 timothee maurin
** Last update Wed May 18 16:49:51 2011 timothee maurin
*/

#include <string.h>
#include "shell.h"
#include "prototype.h"

void	put_in_buf(char *buf, char *dest, int begin)
{
  my_strcpy(&(dest[begin + strlen(buf)]), &(dest[begin]));
  my_strcpy(&(dest[begin]), buf);
}
