/*
** termcap.c for 42sh  in /home/vailla_y//Projet/42sh/src
** 
** Made by yann vaillant
** Login   <vailla_y@epitech.net>
** 
** Started on  Tue Apr 19 15:30:15 2011 yann vaillant
** Last update Thu May 19 20:20:04 2011 maxime constantinian
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
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"shell.h"
#include	"prototype.h"
#include	"termcap_include.h"

int		init_termios(struct termios *term2)
{
  tgetent(NULL, "xterm");
  if (tcgetattr(0, term2) == -1)
    {
      fprintf(stderr, "Erreur tcgetattr\n");
      return (1);
    }
  return (0);
}

int		mode_raw(struct termios *term2)
{
  term2->c_lflag &= ~ICANON;
  term2->c_cc[VMIN] = 1;
  term2->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, term2) == -1)
    {
      fprintf(stderr, "Erreur tcsetattr\n");
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
  if (tcsetattr(0, TCSANOW, term2) == -1)
    {
      fprintf(stderr, "Erreur tcsetattr\n");
      return (1);
    }
  return (0);
}

int     activate_ultra_secret_mode(struct termios *t)
{
  t->c_lflag &= ~ECHO;
  if (tcsetattr(0, TCSANOW, t) == -1)
    {
      fprintf(stderr, "Erreur tcsetattr\n");
      return (1);
    }
  return (0);
}

int     desactivate_ultra_secret_mode(struct termios *t)
{
  t->c_lflag &= ECHO;
  if (tcsetattr(0, TCSANOW, t) == -1)
    {
      fprintf(stderr, "Erreur tcsetattr\n");
      return (1);
    }
  return (0);
}
