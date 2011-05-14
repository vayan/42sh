/*
** place_cursor.c for 42sh in /home/maurin_t//42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May  4 20:34:15 2011 timothee maurin
** Last update Sat May 14 15:34:24 2011 timothee maurin
*/

#include	"shell.h"
#include	"prototype.h"

void		place_cursor_del(int i, int pos, char *buf, int test)
{
  static int	max;

  if (test == 1)
    max = 0;
  else
    {
      if (max < (cur_pos(buf, i) / nbr_column()))
	max = cur_pos(buf, i) / nbr_column();
      if (max - (cur_pos(buf, pos) / nbr_column()) > 0)
	exec_parm("DO", max - (cur_pos(buf, pos) / nbr_column()));
      if (test != 2)
	{
	  if (max > 0)
	    exec_parm("UP", max);
	  exec_str("cr");
	  exec_str("cd");
	}
    }
}

void		place_cursor(int i, int pos, char *buf)
{
  if (i != pos && 
      (cur_pos(buf, i) / nbr_column() - cur_pos(buf, pos) / nbr_column()) > 0)
    exec_parm("UP", (cur_pos(buf, i)) / nbr_column()
	      - cur_pos(buf, pos) / nbr_column());
  exec_parm("ch", cur_pos(buf, pos) % nbr_column());
}

void		place_cursor_back(int i, int pos, char *buf)
{
  if ((cur_pos(buf, i) - 1) / nbr_column()
      - (cur_pos(buf, pos) - 1) / nbr_column() > 0)
    exec_parm("UP", (cur_pos(buf, i) - 1) / nbr_column()
              - (cur_pos(buf, pos) - 1) / nbr_column());
  exec_parm("ch", cur_pos(buf, pos) % nbr_column());
}

void		clear_it(int *pos, int *i, char *buf)
{
  int		tmp;

  tmp = 0;
  while (tmp < (cur_pos(buf, *i)) / (nbr_column())
	 - (cur_pos(buf, *pos)) / (nbr_column()))
    {
      exec_parm("do", 1);
      tmp++;
    }
  tmp = (cur_pos(buf, *i) + 1) / (nbr_column());
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
