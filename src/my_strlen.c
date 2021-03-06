/*
** my_strlen.c for 42sh in /home/consta_m/prog/42sh/src
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sat Apr 30 15:37:02 2011 maxime constantinian
** Last update Sun May 22 18:49:03 2011 maxime constantinian
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
    {
      if (str[i] == '"')
	{
	  i++;
	  while (str[i] && str[i] != '"')
	    i++;
	}
      if (str[i])
	i++;
    }
  return (i);
}

int		my_strlen_createtab_rc(char *str)
{
  int		i = 0;

  while (str[i] && str[i] != ' ' && str[i] != '\t')
    i++;
  return (i);
}

int		my_strlen_create_red(char *str)
{
  int		i = 0;

  while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != ';'
	 && strncmp(&str[i], "&&", 2) != 0  && strncmp(&str[i], "||", 2) != 0
	 && str[i] != '|')
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
