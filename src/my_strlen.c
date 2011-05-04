/*
** my_strlen.c for 42sh in /home/consta_m/prog/42sh/src
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sat Apr 30 15:37:02 2011 maxime constantinian
** Last update Wed May  4 16:16:26 2011 maxime constantinian
*/

#include	<string.h>

int		my_strlen_quote(char *str)
{
  int		i = 0;

  while (str[i] && str[i] != '"')
    i++;
  return (i);
}

int		my_strlen_createtab(char *str)
{
  int		i = 0;

  while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != ';'
	 && strncmp(&str[i], "&&", 2) != 0  && strncmp(&str[i], "||", 2) != 0
	 && str[i] != '|' && strncmp(&str[i], "<<", 2) != 0 && str[i] != '<'
	 && strncmp(&str[i], ">>", 2) != 0 && str[i] != '>')
    i++;
  return (i);
}

int		my_strlen_hach(char *str)
{
  int		i = 0;

  while (str[i] && str[i] != ':')
    i++;
  return (i);
}
