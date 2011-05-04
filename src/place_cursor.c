/*
** place_cursor.c for 42sh in /home/maurin_t//42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May  4 20:34:15 2011 timothee maurin
** Last update Wed May  4 20:40:36 2011 timothee maurin
*/

#include	"shell.h"
#include	"prototype.h"

void		place_cursor(int i, int pos)
{
  int		a;

  a = 0;
  while (i - a > pos)
    {
      if (((i - a + 3) % (nbr_column())) == 0)
        {
          if ((i - a + 3) / (nbr_column()))
            {
              exec_parm("up", 1);
              exec_parm("ch", nbr_column());
            }
        }
      else
        xwrite(0, "\b", 1);
      a++;
    }
}

void		place_cursor_back(int i, int pos)
{
  if ((i + 1) / nbr_column() - (pos + 2) / nbr_column() > 0)
    exec_parm("up", (i + 1) / nbr_column() - (pos + 2) / nbr_column());
  exec_parm("ch", ((pos + 2) % nbr_column()));
}
