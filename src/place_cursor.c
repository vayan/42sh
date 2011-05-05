/*
** place_cursor.c for 42sh in /home/maurin_t//42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May  4 20:34:15 2011 timothee maurin
** Last update Thu May  5 13:25:17 2011 timothee maurin
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
