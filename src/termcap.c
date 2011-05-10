/*
** termcap.c for 42sh  in /home/vailla_y//Projet/42sh/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Apr 19 15:30:15 2011 yann vaillant
** Last update Fri May  6 18:48:17 2011 maxime constantinian
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
#include	"shell.h"
#include	"prototype.h"
#include	"termcap_include.h"
#include	<errno.h>
#include	<string.h>
int		init_termios(struct termios *term2)
{
  char		*termtype;

  termtype = getenv("TERM");
  tgetent(NULL, termtype);
  if (ioctl(STDIN_FILENO, TCGETS, term2) == -1)
    {
      fprintf(stderr, "ioctl: %s\n %d", strerror(errno), STDIN_FILENO);
      fprintf(stderr, "Erreur ioctl\n");
      return (1);
    }
  return (0);
}

int		mode_raw(struct termios *term2)
{
  term2->c_lflag &= ~ICANON;
  term2->c_cc[VMIN] = 1;
  term2->c_cc[VTIME] = 0;
  if (ioctl(STDIN_FILENO, TCSETS, term2) == -1)
    {
      fprintf(stderr, "ioctl: %s\n %d", strerror(errno), STDIN_FILENO);
      /* fprintf(stderr, "Erreur ioctl\n"); */
      return (1);
    }
  exec_str("bw");
  return (0);
}

int		desactivate_mode_raw(struct termios *term2)
{
  static int	lflag;

  if (lflag == 0)
    lflag = term2->c_lflag;
  term2->c_lflag = lflag;
  if (ioctl(STDIN_FILENO, TCSETS, term2) == -1)
    {
      fprintf(stderr, "ioctl: %s\n %d", strerror(errno), STDIN_FILENO);
      fprintf(stderr, "Erreur ioctl\n");
      return (1);
    }
  return (0);
}

int     activate_ultra_secret_mode(struct termios *t)
{
  t->c_lflag &= ~ECHO;
  if (ioctl(STDIN_FILENO, TCSETS, t) == -1)
    {
      fprintf(stderr, "ioctl: %s\n %d", strerror(errno), STDIN_FILENO);
      fprintf(stderr, "Erreur ioctl\n");
      return (1);
    }
  return (0);
}

int     desactivate_ultra_secret_mode(struct termios *t)
{
  t->c_lflag &= ECHO;
  if (ioctl(STDIN_FILENO, TCSETS, t) == -1)
    {
      fprintf(stderr, "ioctl: %s\n %d", strerror(errno), STDIN_FILENO);
      fprintf(stderr, "Erreur ioctl\n");
      return (1);
    }
  return (0);
}
