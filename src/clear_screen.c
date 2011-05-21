/*
** clear_screen.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Fri May 20 19:45:18 2011 timothee maurin
** Last update Sun May 22 01:29:11 2011 timothee maurin
*/

#include "shell.h"
#include "prototype.h"

void	clr_screen(char *buf, int i, int pos)
{
  exec_str("cl");
  aff_prompt(2);
  my_putstr_del(buf);
  place_cursor(i, pos, buf);
}
