/*
** get_next_line.h for get_next_line in /home/consta_m//getnext
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue Nov 23 14:38:52 2010 maxime constantinian
** Last update Sat Nov 27 02:17:19 2010 maxime constantinian
*/

#ifndef		__GET_NEXT_LINE__
# define	__GET_NEXT_LINE__

# define	BUFFERSIZE 10
# define	NBRREAD 5

typedef struct	s_var
{
  int		ret;
  char		*s;
  int		i;
  int		i2;
  int		size;
}		t_var;

char		*get_next_line(const int fd);
int		start_cal(t_var *var, char *buffer, const int fd);

#endif
