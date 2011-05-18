/*
** completion.h for 42sh in /home/maurin_t//mesfonction/42sh/include
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat May 14 17:50:25 2011 timothee maurin
** Last update Wed May 18 15:56:07 2011 timothee maurin
*/

#ifndef __COMPLETION_H__
# define __COMPLETION_H__

typedef struct s_completion
{
  char			*buf;
  struct s_completion	*next;
}			t_completion;

#endif
