/*
** graph.h for 42sh in /home/consta_m/prog/42sh/include
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed Apr  6 11:59:49 2011 maxime constantinian
** Last update Tue Apr 26 18:07:14 2011 yann vaillant
*/

#ifndef		GRAPH_H__
# define	GRAPH_H__

typedef struct	s_hach
{
  char		*path;
  struct s_hach	**next;
}		t_hach_bin;

//void		create_hach(char *path, t_hach_bin *tab);
//char		*recup_hach(t_hach_bin *tab, char *name);

#endif