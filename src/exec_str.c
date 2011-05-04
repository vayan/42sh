/*
** exec_str.c for alum1 in /home/consta_m/
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Thu Feb  3 13:38:29 2011 maxime constantinian
** Last update Wed May  4 17:52:00 2011 timothee maurin
*/

#include	<curses.h>
#include	<term.h>
#include	"shell.h"
#include	"prototype.h"

int		my_putchar(int c)
{
  return (xwrite(0, (char *)&c, 1));
}

void		exec_str(char *str)
{
  char		**area;
  char		*ins;

  area = 0;
  if ((ins = tgetstr(str, area)))
    tputs(ins, 1, &my_putchar);
}

void		exec_parm(char *str, int nb)
{
  char		**area;
  char		*ins;

  area = 0;
  if ((ins = tgetstr(str, area)))
    tputs(tparm(ins, nb), 1, my_putchar);
}
