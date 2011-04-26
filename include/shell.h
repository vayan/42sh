/*
** 42sh.h for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed Apr 20 13:13:56 2011 maxime constantinian
** Last update Tue Apr 26 14:17:37 2011 maxime constantinian
*/

#ifndef		SHELL_H__
# define	SHELL_H__

typedef struct		s_list_var
{
  char			*name;
  char			*var;
  struct s_list_var	*next;
}			t_list_var;

typedef struct		s_commande
{
  int			type;
  char			**cmd;
  struct s_commande	**next_cmd;
  struct s_commande	*before_historique;
  struct s_commande	*next_historique;
}			t_commande;

typedef struct		s_shell
{
  t_hach_bin		*tab_hach;
  char			**env;
  t_list_var		*variable;
  t_commande		*commande;
}			t_shell;

#endif
