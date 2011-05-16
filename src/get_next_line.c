/*
** get_next_line.c for gnl in /home/consta_m//getnext/test2
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Fri Nov 26 19:05:23 2010 maxime constantinian
** Last update Mon May 16 19:02:14 2011 maxime constantinian
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"shell.h"
#include	"prototype.h"
#include	"get_next_line.h"

void		init_tab(char *str)
{
  int		count;

  count = 0;
  while (count < BUFFERSIZE)
    {
      str[count] = 0;
      count++;
    }
}

char		*my_fakerealloc(t_var *var)
{
  char		*s_final;
  int		count;

  count = 0;
  var->size = var->size + 1;
  s_final = xmalloc((BUFFERSIZE * var->size) + 1);
  while (count < (BUFFERSIZE * var->size))
    {
      if (count < (BUFFERSIZE * (var->size - 1)))
	s_final[count] = var->s[count];
      else
	s_final[count] = 0;
      count++;
    }
  free(var->s);
  return (s_final);
}

int		end_cal(t_var *var, char *buffer, const int fd)
{
  if (var->ret != -1)
    {
      if (var->ret == 0)
	return (0);
      else
	{
	  while (buffer[var->i] != '\n' && buffer[var->i])
	    {
	      var->s[var->i2] = buffer[var->i];
	      (var->i)++;
	      (var->i2)++;
	      if (buffer[var->i] == 0 && var->i == NBRREAD)
		{
		  var->s = my_fakerealloc(var);
		  start_cal(var, buffer, fd);
		}
	    }
	}
    }
  return (1);
}

int		start_cal(t_var *var, char *buffer, const int fd)
{
  if (var->i == 0 || var->i == NBRREAD || buffer[var->i] == 0)
    {
      var->i = 0;
      init_tab(buffer);
      var->ret = read(fd, buffer, NBRREAD);
    }
  if (end_cal(var, buffer, fd) == 0)
    return (0);
  return (1);
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFFERSIZE] = "";
  static int	i;
  t_var		var;

  var.i = i;
  var.i2 = 0;
  var.size = 1;
  var.ret = 1;
  var.s = xmalloc(BUFFERSIZE);
  init_tab(var.s);
  if (start_cal(&var, buffer, fd) == 0 && buffer[0] == 0)
    {
      free(var.s);
      return (0);
    }
  if (buffer[var.i] == '\n')
    (var.i)++;
  i = var.i;
  return (var.s);
}
