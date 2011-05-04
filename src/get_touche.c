
/*
** get_touche.c for 42sh  in /home/vailla_y//Projet/42sh/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Apr 21 17:41:38 2011 yann vaillant
** Last update Wed May  4 01:29:23 2011 maxime constantinian
*/

#include        <sys/ioctl.h>
#include        <sys/types.h>
#include        <termcap.h>
#include        <termios.h>
#include        <stdlib.h>
#include        <curses.h>
#include        <term.h>
#include        <signal.h>

char	*get_touche(struct termios *t)
{
  int	ret;
  char	*touche;

  touche = xmalloc(11 * sizeof(*touche));
  activate_ultra_secret_mode(t);
  ret = read(0, touche, 10);
  touche[ret] = '\0';
  desactivate_ultra_secret_mode(t);
  return (touche);
}
