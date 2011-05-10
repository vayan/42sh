/*
** buffer_utils.c for 42sh in /home/maurin_t//42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May  4 19:59:04 2011 timothee maurin
** Last update Fri May  6 18:49:07 2011 maxime constantinian
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<sys/ioctl.h>
#include	<sys/types.h>
#include	<termcap.h>
#include	<termios.h>
#include	<stdlib.h>
#include	<curses.h>
#include	<term.h>
#include	<signal.h>
#include	<string.h>
#include	"shell.h"
#include	"xmalloc.h"
#include	<errno.h>
#include	<string.h>
int		verif_touche(char *cha)
{
  if (cha[0] < ' ' || cha[0] == 127)
    return (1);
  else
    return (0);
}

int		is_del(char *cha)
{
  if (cha[0] == 27 && cha[1] == 91 && cha[2] == 51 && cha[3] == 126)
    return (1);
  else
    return (0);
}

int			nbr_column()
{
  struct winsize        w;

  if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w) == -1)
    {
      fprintf(stderr, "ioclt: %s %d\n", strerror(errno), STDIN_FILENO);
      fprintf(stderr, "ioclt error\n");
    }
  return (w.ws_col);
}
