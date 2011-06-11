/*
** xsignal.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Sat Jun 11 19:05:54 2011 maxime constantinian
** Last update Sat Jun 11 19:10:17 2011 maxime constantinian
*/

#include	<stdio.h>
#include	<signal.h>
#include	<string.h>
#include	<errno.h>

void		(*xsignal(int sig, void (*func)(int)))(int)
{
  void		(*ret)(int);

  if ((ret = signal(sig, func)) == SIG_ERR)
    fprintf(stderr, "42sh: signal failed: %s.", strerror(errno));
  return (ret);
}
