/*
** prototype.h for  in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 11:14:59 2011 maxime constantinian
** Last update Wed May  4 17:42:21 2011 maxime constantinian
*/

#ifndef		PROTYPE_H__
# define	PROTYPE_H__

char		*my_strcopynalloc(char *str);
char		*my_strcopynalloc_gen(char *str, int len);
void		exec_type_cmd(t_commande *cmd, t_shell *shell);
char		*my_get_env(char *str, char **env);
void		*xmalloc(int size);
char		**str_to_wordtab(char *str);
char		*recup_hach(t_hach_bin *num, char *name);
int		*xpipe(int *num);
int		xfork();
void		xdup2(int oldfd, int newfd);
int		isfile(char *str);
int		my_strlen_hach(char *str);
int		my_strlen_quote(char *str);
int		my_strlen_createtab(char *str);
void		check_commande(char *str, t_commande *cmd);
void		check_pipe(char *str, t_commande *cmd);
void		check_or(char *str, t_commande *cmd);
void		check_and(char *str, t_commande *cmd);
int		if_have_sep(char *str);
int		xwrite(int, char *, int);
void		copy_env(char **env, t_shell *shell);
void		add_hachtab_to_shell(t_shell *shell);
void		parser(char *str, t_shell *shell);
void		exec_cmd(t_shell *shell);

#endif
