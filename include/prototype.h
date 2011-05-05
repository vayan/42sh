/*
** prototype.h for  in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 11:14:59 2011 maxime constantinian
** Last update Thu May  5 17:37:22 2011 timothee maurin
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
char		*concat(char *s1, char *s2);
char		*my_pwd(char *pwd);
int		xwrite(int fd, char *str, int len);
int		verif_touche(char *cha);
int		is_del(char *cha);
int		nbr_column();
void		place_cursor(int i, int pos);
void		place_cursor_back(int i, int pos);
void		clear_it(int *pos, int *i);
void		func_remove(char *cha, int *i, int *pos, char *buf);
char		*other_cha(char cha, char *buf, int *pos, int *i);
void		func_fleche(char *cha, int *i, int *pos);
void		exec_parm(char *str, int nb);
char		*my_strcpy(char *dest, char *src);
char		*my_strcpy_buf(char *dest, char *src);
void		exec_str(char *str);
int		my_putstr_buf(char *str);
void		init_new_cmd(t_shell *shell);
void            funct_exit(int sig);
void            funct_noexit(int sig);

#endif