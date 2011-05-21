/*
** prototype.h for  in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 11:14:59 2011 maxime constantinian
** Last update Sun May 22 01:46:02 2011 timothee maurin
*/

#ifndef		PROTYPE_H__
# define	PROTYPE_H__

char		*my_strcopynalloc(char *str);
char		*my_strcopynalloc_gen(char *str, int len);
int		exec_type_cmd(t_commande *cmd, t_shell *shell, int *tabs);
char		*my_get_env(char *str, char **env);
void		*xmalloc(int size);
char		**str_to_wordtab(char *str);
char		**str_to_wordtab_red(char *str);
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
void		check_redirection(char *str, t_commande *cmd);
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
int		verif_touche(char *cha, int i);
int		is_del(char *cha);
int		nbr_column();
void		place_cursor(int i, int pos, char *buf);
void		place_cursor_back(int i, int pos, char *buf);
void		clear_it(int *pos, int *i, char *buf);
void		func_remove(char *cha, int *i, int *pos, char *buf);
char		*other_cha(char cha, char *buf, int *pos, int *i);
void		func_fleche(char *cha, int *i, int *pos, char **buf);
void		exec_parm(char *str, int nb);
char		*my_strcpy(char *dest, char *src);
char		*my_strcpy_buf(char *dest, char *src);
void		exec_str(char *str);
int		my_putstr_buf(char *str, int i1, int pos, char *buf);
void		init_new_cmd(t_shell *shell);
void		funct_exit(int sig);
void		funct_noexit(int sig);
t_shell		*recup_shell(t_shell *ptr);
void		funct_histo(char *cha, int *i,
			    int *pos, char **buf);
void		reaf(int *i, int *pos, char *buf);
char		*free_buf(char *buf, int test);
t_commande_root	*recup_com(t_shell *shell, int test);
int		xread(int fd, char *buf, int nb);
int		nbr_column();
int		cur_pos(char *buf, int i, int test);
void		place_cursor_del(int i, int pos, char *buf, int test);
void		my_putstr_del(char *buf);
int		srd_fonction(t_commande *cmd, t_shell *shell, int *tab1);
int		srl_fonction(t_commande *cmd, t_shell *shell, int *tab1);
int		drd_fonction(t_commande *cmd, t_shell *shell, int *tab1);
int		drl_fonction(t_commande *cmd, t_shell *shell, int *tab1);
char		*get_next_line(int fd);
int		check_equal(char *str);
int		strlen_equal(char *av);
t_list_var	*remove_var_in_list(char *name_var, t_list_var *list_var);
t_list_var	*update_var_in_list(char **name_var, t_list_var *list_var);
int		check_if_exist_in_list(char *name_var, t_list_var *list_var);
t_list_var	*add_var_to_list(char **name_var, t_list_var *list_var);
void		aff_prompt(int test);
int		aff_env(char **env, int *tb);
int		exec_in_builtin(char **cmdeuh, t_shell *shell,
				char **env, int *tb);
char		*get_prompt(t_shell *shell);
char		*current_folder();
char		*folder_to_home();
char		*current_shell();
char		*time_system();
char		*time_system_sec();
char		*date_system();
char		*pseudo_user();
char		*real_name();
char		*name_host_pc();
int		my_strlen_quote(char *str);
int		my_strlen_createtab_rc(char *str);
int		count_word(char *str);
char		*path_file();
void		free_tab(char **tab);
void		test_set(char **name_var, t_list_var **buffer,
			 t_list_var **list_var);
void		test_alias(char **name_var, t_list_var **alias_buf,
                   t_list_var **alias);

#endif
