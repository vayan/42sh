/*
** check_redirection.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue May 10 21:34:38 2011 maxime constantinian
** Last update Wed May 11 01:47:00 2011 maxime constantinian
*/

#include	"shell.h"
#include	"prototype.h"

void		check_redirection(char *str, t_commande *cmd)
{
  char		**tab;
  int		i;

  i = 0;
  tab = str_to_wordtab_red(str);
  check_commande(str, cmd);
}
