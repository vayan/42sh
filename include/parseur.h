/*
** parseur.h for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Tue Apr 26 23:53:10 2011 maxime constantinian
** Last update Wed May  4 00:25:51 2011 maxime constantinian
*/

#ifndef		PARSEUR_H__
# define	PARSEUR_H__

# define	OP_SEP 1
# define	OP_AND 2
# define	OP_OR  3
# define	OP_PIP 4
# define	OP_SRR 5
# define	OP_SRL 6
# define	OP_DRR 7
# define	OP_DRL 8
# define	CMD    9
# define	FILE   10

void		check_double_left(char *str, t_commande *cmd);

#endif		/* PARSEUR_H__ */
