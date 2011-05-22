/*
** completion.h for 42sh in /home/maurin_t//mesfonction/42sh/include
** 
** Made by timothee maurin
** Login   <maurin_t@epitech.net>
** 
** Started on  Sat May 14 17:50:25 2011 timothee maurin
** Last update Sun May 22 15:46:08 2011 timothee maurin
*/

#ifndef __COMPLETION_H__
# define __COMPLETION_H__

typedef struct s_completion
{
  char			*buf;
  struct s_completion	*next;
}			t_completion;

t_completion    *free_list(t_completion *);
void            traiter_list(t_completion *, char *,
			     int *, int *);
t_completion    *find_completion(int typ, char *bf, int pos, int begin);
int             my_put_in_list(char *buf, t_completion **list);
DIR		*xopendir(char *dir);
t_completion	*find_commande(char *buf, int pos,
			       int begin, t_hach_bin *hach);
t_completion	*find_in_folder(char *buf, int pos, int begin);

#endif
