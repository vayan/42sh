/*
** termcap.c for 42sh  in /home/vailla_y//Projet/42sh/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Apr 19 15:30:15 2011 yann vaillant
** Last update Tue May  3 17:26:54 2011 timothee maurin
*/

#include        <unistd.h>
#include        <stdio.h>
#include        <sys/ioctl.h>
#include        <sys/types.h>
#include        <termcap.h>
#include        <termios.h>
#include        <stdlib.h>
#include        <curses.h>
#include        <term.h>
#include        <signal.h>

int  mode_raw(struct termios *term2)
{
  char          *termtype;

  termtype = getenv("TERM");
  tgetent(NULL, termtype);
  if (ioctl(STDIN_FILENO, TCGETS, term2) == -1)
    {
      fprintf(stderr, "Erreur ioctl\n");
      return (1);
    }
  term2->c_lflag &= ~ICANON;
  term2->c_cc[VMIN] = 1;
  term2->c_cc[VTIME] = 0;
  if (ioctl(STDIN_FILENO, TCSETS, term2) == -1)
    {
      fprintf(stderr, "Erreur ioctl\n");
      return (1);
    }
  exec_str("bw");
  return (0);
}

int     activate_ultra_secret_mode(struct termios *t)
{
  t->c_lflag &= ~ECHO;
  if (ioctl(STDIN_FILENO, TCSETS, t) == -1)
    {
      fprintf(stderr, "Erreur ioctl");
      return (1);
    }
  return (0);
}

int     desactivate_ultra_secret_mode(struct termios *t)
{
  t->c_lflag &= ECHO;
  if (ioctl(STDIN_FILENO, TCSETS, t) == -1)
    {
      fprintf(stderr, "Erreur ioctl");
      return (1);
    }
  return (0);
}
