/*
** which_type.c for 42sh in /home/maurin_t//mesfonction/42sh/src
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Wed May 18 17:56:30 2011 timothee maurin
** Last update Sun Jun 12 04:19:20 2011 timothee maurin
*/

#include	<sys/types.h>
#include	<dirent.h>
#include	"shell.h"
#include	"prototype.h"
#include	"completion.h"

int		which_type(char *buf, int pos, int *begin)
{
  *begin = pos;
  if (pos == 0 || buf[pos - 1] == ';' || buf[pos - 1] == 9
      || buf[pos - 1] == ' ')
    return (0);
  else
    {
      while (pos > 0 && buf[pos] !=  ' ' && buf[pos] != 9 && buf[pos] != ';')
	pos--;
      *begin = pos + 1;
      while ((buf[pos] == ' ' || buf[pos] == 9) && pos > 0)
	pos--;
      if (buf[pos] == '|' || buf[pos] == '&' || buf[pos] == ';' || pos == 0)
	return (1);
      else
        return (0);
    }
}

int		which_type_alias(char *buf, int pos, int *begin)
{
  if (pos == 0 || buf[pos - 1] == ';')
    return (0);
  else
    {
      while (pos > 0 && ((buf[pos] !=  ' ' && buf[pos] != 9 && buf[pos] != ';'
			  && buf[pos] != '&' && buf[pos] != '|')))
	pos--;
      *begin = pos + 1;
      while ((buf[pos] == ' ' || buf[pos] == 9) && pos > 0)
	pos--;
      if (buf[pos] == ';' || buf[pos] == '&' || buf[pos] == '|')
        {
          if ((pos == 0 && (buf[pos] == ' ' || buf[pos] == 9)))
	    return (1);
          else
	    return (0);
        }
      else
        return (1);
    }
}
