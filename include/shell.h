/*
** 42sh.h for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed Apr 20 13:13:56 2011 maxime constantinian
** Last update Mon May 16 14:26:33 2011 maxime constantinian
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
  struct s_commande	**next;
}			t_commande;

typedef struct			s_commande_root
{
  struct s_commande		*cmd;
  char				*buffer;
  struct s_commande_root	*before_histo;
  struct s_commande_root	*next_histo;
}				t_commande_root;

typedef struct		s_hach_bin
{
  char			*path;
  struct s_hach_bin	**next;
}			t_hach_bin;

typedef struct		s_shell
{
  t_hach_bin		*tab_hach;
  char			**env;
  t_list_var		*alias;
  t_list_var		*variable;
  t_commande_root	*commande;
}			t_shell;

#endif
