/*
** main.c for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue Mar  8 11:45:43 2011 maxime constantinian
** Last update Tue Apr 19 16:18:40 2011 yann vaillant
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

int		main()
{
  struct termios term;
  
  mode_raw(&term);       
  return (0);
}
