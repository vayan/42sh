/*
** buffer_utils.c for 42sh in /home/maurin_t//42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May  4 19:59:04 2011 timothee maurin
** Last update Tue May 10 14:43:10 2011 timothee maurin
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<termcap.h>
#include<termios.h>
#include<stdlib.h>
#include<curses.h>
#include<term.h>
#include<signal.h>
#include<string.h>
#include"shell.h"
#include"xmalloc.h"
#include<errno.h>
#include<string.h>
intverif_touche(char *cha)
{
  if (cha[0] < ' ' || cha[0] == 127)
    return (1);
  else
    return (0);
}

intis_del(char *cha)
{
  if (cha[0] == 27 && cha[1] == 91 && cha[2] == 51 && cha[3] == 126)
    return (1);
  else
    return (0);
}

intnbr_column()
{
  struct winsize        w;

  if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w) == -1)
    {
      fprintf(stderr, "ioclt: %s %d\n", strerror(errno), STDIN_FILENO);
      fprintf(stderr, "ioclt error\n");
    }
  return (w.ws_col);
}
