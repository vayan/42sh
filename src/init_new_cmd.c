/*
** init_new_cmd.c for 42sh in /home/consta_m/prog/42sh/src
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Fri Apr 29 19:02:04 2011 maxime constantinian
** Last update Fri Apr 29 19:03:25 2011 maxime constantinian
*/

#include	"shell.h"
#include	"parseur.h"

void		init_new_cmd(t_shell *shell)
{
  if (shell->commande == 0)
    shell->commande = xmalloc(sizeof(*(shell->commande)));
  else
    {
      shell->commande->next_histo = xmalloc(sizeof(*(shell->commande)));
      shell->commande->next_histo->before_histo = shell->commande;
      shell->commande = shell->commande->next_histo;
    }
}
