/*
** init_new_cmd.c for 42sh in /home/consta_m/prog/42sh/src
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Fri Apr 29 19:02:04 2011 maxime constantinian
** Last update Wed Jun  8 19:06:29 2011 maxime constantinian
*/

#include	<unistd.h>
#include	"shell.h"
#include	"prototype.h"

void		init_new_cmd(t_shell *shell)
{
  aff_prompt(2);
  if (shell->commande == 0)
    shell->commande = xmalloc(sizeof(*(shell->commande)));
  else
    {
      if (shell->commande->next_histo != 0)
	while (shell->commande->next_histo != 0)
	  shell->commande = shell->commande->next_histo;
      shell->commande->next_histo = xmalloc(sizeof(*(shell->commande)));
      shell->commande->next_histo->before_histo = shell->commande;
      shell->commande = shell->commande->next_histo;
    }
  place_cursor_del(0, 0, 0, 1);
  shell->commande->buffer = xmalloc(8193 * sizeof(*(shell->commande->buffer)));
  free_buf(shell->commande->buffer, 0);
}
