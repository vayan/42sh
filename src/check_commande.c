/*
** check_commande.c for 42sh in /home/consta_m/prog/42sh/src
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Fri Apr 29 16:53:47 2011 maxime constantinian
** Last update Wed May  4 16:26:15 2011 maxime constantinian
*/

#include	"shell.h"
#include	"parseur.h"
#include	"prototype.h"

void		check_commande(char *str, t_commande *cmd)
{
  cmd->type = CMD;
  cmd->cmd = str_to_wordtab(str);
}
