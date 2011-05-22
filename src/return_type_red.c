/*
** return_type_red.c for return_type_red in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sun May 22 15:52:44 2011 timothee maurin
** Last update Sun May 22 15:54:47 2011 timothee maurin
*/

#include	<string.h>

int             return_type_red(char *str)
{
  if (strncmp(str, "<<", 2) == 0)
    return (1);
  else if (strncmp(str, ">>", 2) == 0)
    return (2);
  else if (str[0] == '<')
    return (3);
  else if (str[0] == '>')
    return (4);
  return (0);
}
