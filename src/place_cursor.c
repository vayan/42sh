/*
** place_cursor.c for 42sh in /home/maurin_t//42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May  4 20:34:15 2011 timothee maurin
** Last update Thu May  5 13:30:16 2011 timothee maurin
*/

#include	"shell.h"
#include	"prototype.h"

void		place_cursor(int i, int pos)
{
  if ((i + 2) / nbr_column() - (pos + 2) / nbr_column() > 0)
    exec_parm("up", (i + 2) / nbr_column() - (pos + 2) / nbr_column());
  exec_parm("ch", ((pos + 2) % nbr_column()));
}

void		place_cursor_back(int i, int pos)
{
  if ((i + 1) / nbr_column() - (pos + 2) / nbr_column() > 0)
    exec_parm("up", (i + 1) / nbr_column() - (pos + 2) / nbr_column());
  exec_parm("ch", ((pos + 2) % nbr_column()));
}

void		clear_it(int *pos, int *i)
{
  static int	max;
  int		tmp;

  tmp = 0;
  if (max < ((*i) + 2) / (nbr_column()))
    max = (((*i) + 2) / (nbr_column()));
  while (tmp < max - ((*pos) + 3) / (nbr_column()))
    {
      exec_parm("do", 1);
      tmp++;
    }
  tmp = max;
  while (tmp > 0)
    {
      exec_str("cr");
      exec_str("cd");
      exec_parm("up", 1);
      tmp--;
    }
  exec_str("cr");
  exec_str("cd");
}
