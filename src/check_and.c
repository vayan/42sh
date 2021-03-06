/*
** check_and.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Thu Apr 28 16:44:10 2011 maxime constantinian
** Last update Wed May  4 16:30:59 2011 maxime constantinian
*/

#include	<string.h>
#include	"shell.h"
#include	"parseur.h"
#include	"prototype.h"

int		if_have_and(char *str)
{
  int		i = 0;
  int		nb_and = 0;

  if (str == 0)
    return (0);
  while (str[i] && str[i] != ';')
    {
      if (str[i] == '"')
	{
	  i++;
	  while (str[i] && str[i] != '"')
	    i++;
	}
      if (strncmp(&str[i], "&&", 2) == 0)
	nb_and++;
      if (str[i])
	i++;
    }
  return (nb_and);
}

void		check_and(char *str, t_commande *cmd)
{
  int		nb_and;
  int		i = 0;

  nb_and = if_have_and(str);
  if (nb_and)
    {
      cmd->type = OP_AND;
      cmd->next = xmalloc(sizeof(*(cmd->next)) * (3));
      cmd->next[0] = xmalloc(sizeof(t_commande));
      check_or(str, cmd->next[0]);
      while (str[i] && str[i] != ';' && strncmp(&str[i], "&&", 2) != 0)
	i++;
      if (strncmp(&str[i], "&&", 2) == 0)
	{
	  i += 2;
	  cmd->next[1] = xmalloc(sizeof(t_commande));
	  check_and(&str[i], cmd->next[1]);
	}
    }
  else
    check_or(str, cmd);
}
