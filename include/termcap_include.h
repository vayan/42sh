/*
** termcap.h for 42sh in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 16:44:26 2011 maxime constantinian
** Last update Wed May  4 17:39:01 2011 maxime constantinian
*/

#ifndef		TERMCAP_H__
# define	TERMCAP_H__

int		mode_raw(struct termios *term2);
int		activate_ultra_secret_mode(struct termios *t);
int		desactivate_ultra_secret_mode(struct termios *t);
void		exec_str(char *str);
void            get_next_comm(t_shell *shell, struct termios *term2);

#endif
