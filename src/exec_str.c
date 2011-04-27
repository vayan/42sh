/*
** exec_str.c for alum1 in /home/consta_m/
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Thu Feb  3 13:38:29 2011 maxime constantinian
** Last update Wed Apr 27 18:03:38 2011 maxime constantinian
*/

#include	<curses.h>
#include	<term.h>

void		exec_str(char *str)
{
  char		**area;
  char		*ins;

  area = 0;
  if ((ins = tgetstr(str, area)))
    tputs(ins, 1, &my_putchar);
}
