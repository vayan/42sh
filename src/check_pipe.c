/*
** check_pipe.c for 42sh in /home/consta_m/prog/42sh/src
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Fri Apr 29 15:20:29 2011 maxime constantinian
** Last update Wed May  4 03:51:09 2011 maxime constantinian
*/

#include	"shell.h"
#include	"parseur.h"

int		if_have_pipe(char *str)
{
  int		nb_pipe = 0;
  int		i = 0;

  if (str == 0)
    return (0);
  while (str[i] && str[i] != ';' && strncmp(&str[i], "&&", 2) != 0
	 && strncmp(&str[i], "||", 2) != 0)
    {
      if (str[i] == '"')
	{
	  i++;
	  while (str[i] && str[i] != '"')
	    i++;
	}
      if (str[i] == '|')
	nb_pipe++;
      if (str[i])
	i++;
    }
  return (nb_pipe);
}

void		check_pipe(char *str, t_commande *cmd)
{
  int		nb_pipe;
  int		i = 0;

  nb_pipe = if_have_pipe(str);
  if (nb_pipe)
    {
      cmd->type = OP_PIP;
      cmd->next = xmalloc(sizeof(*(cmd->next)) * (3));
      cmd->next[0] = xmalloc(sizeof(t_commande));
      check_commande(str, cmd->next[0]);
      while (str[i] && str[i] != ';' && strncmp(&str[i], "&&", 2) != 0
	     && strncmp(&str[i], "||", 2) != 0 && str[i] != '|')
	i++;
      if (strncmp(&str[i], "||", 2) != 0 && str[i] == '|')
	{
	  i++;
	  cmd->next[1] = xmalloc(sizeof(t_commande));
	  check_pipe(&str[i], cmd->next[1]);
	}
    }
  else
    check_commande(str, cmd);
}
