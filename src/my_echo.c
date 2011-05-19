/*
** my_echo.c for echo in /home/pugeat_j/
** 
** Made by justin pugeat
** Login   <pugeat_j@epitech.net>
** 
** Started on  Fri Apr 29 15:47:45 2011 justin pugeat
** Last update Thu May 19 19:19:27 2011 timothee maurin
*/

#include <string.h>
#include <stdio.h>

int	my_echo(char **str, char **env, int *tab)
{
  int	i = 1;
  char	opt_n = 0;

  env = env;
  while (str[i])
    {
      if (strcmp(str[i], "-n") == 0 && i == 1)
	opt_n = 1;
      else
	{
	  xwrite(tab[1], str[i], strlen(str[i]));
	  if (str[i + 1] != '\0')
	    xwrite(tab[1], " ", 1);
	}
      i++;
    }
  if (opt_n == 0)
    xwrite(tab[1], "\n", 1);
  return (0);
}
