/*
** get_touche.c for 42sh  in /home/vailla_y//Projet/42sh/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Thu Apr 21 17:41:38 2011 yann vaillant
** Last update Wed May 18 20:19:25 2011 timothee maurin
*/

#include	<unistd.h>
#include        <sys/ioctl.h>
#include        <sys/types.h>
#include        <termcap.h>
#include        <termios.h>
#include        <stdlib.h>
#include        <curses.h>
#include        <term.h>
#include        <signal.h>
#include	"shell.h"
#include	"prototype.h"
#include	"termcap_include.h"

char	*get_touche(struct termios *t)
{
  char	*touche;

  touche = xmalloc(4097 * sizeof(*touche));
  activate_ultra_secret_mode(t);
  xread(0, touche, 4096);
  desactivate_ultra_secret_mode(t);
  return (touche);
}
