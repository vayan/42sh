/*
** place_cursor.c for 42sh in /home/maurin_t//42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May  4 20:34:15 2011 timothee maurin
** Last update Sat May 14 16:43:39 2011 timothee maurin
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
