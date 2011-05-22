/*
** which_type.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May 18 17:56:30 2011 timothee maurin
** Last update Sun May 22 02:34:56 2011 timothee maurin
*/

#include	<sys/types.h>
#include	<dirent.h>
#include	"shell.h"
#include	"prototype.h"
#include	"completion.h"

int		which_type(char *buf, int pos, int *begin)
{
  int		save_pos;

  save_pos = pos;
  *begin = pos;
  if (pos == 0 || buf[pos] == ';')
    return (0);
  else
    {
      while (pos > 0 && buf[pos] !=  ' '
	     && buf[pos] != 9 && buf[pos--] != ';');
      *begin = pos + 1;
      if (buf[pos] == ' ' || buf[pos] == 9)
        {
          while ((buf[pos] == ' ' || buf[pos] == 9) && pos > 0)
            pos--;
          if ((pos == 0 && (buf[pos] == ' ' || buf[pos] == 9))
	       || buf[pos] == ';')
            return (1);
          else
            return (0);
        }
      else
        return (1);
    }
}
