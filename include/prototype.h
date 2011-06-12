/*
** prototype.h for  in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 11:14:59 2011 maxime constantinian
** Last update Sun Jun 12 19:24:20 2011 maxime constantinian
*/

#ifndef		PROTYPE_H__
# define	PROTYPE_H__

int		aff_var(t_list_var *list_var, int *tb);
int             check_if_have_cmd(t_commande *cmd);
int		my_unset_alias(char **av);
int             my_set_alias(char **av, int *tb);
int		which_type_alias(char *buf, int pos, int *begin);
char		*funct_alias(char *cmd, t_shell *sh, int i);
int		return_type_red(char *str);
char		*my_strcopynalloc(char *str);
char		*my_strcopynalloc_gen(char *str, int len);
int		exec_type_cmd(t_commande *cmd, t_shell *shell, int *ta, int i);
char		*my_get_env(char *str, char **env);
void		*xmalloc(int size);
char		**str_to_wordtab(char *str);
char		**str_to_wordtab_red(char *str);
char		*recup_hach(t_hach_bin *num, char *name);
int		*xpipe(int *num, int mode);
int		xfork(int mode);
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
int		copy_env(char **env, t_shell *shell);
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
t_list_var	*remove_var_in_list(char *name_var, t_list_var **list_var,
				    t_list_var *tmp);
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
int		free_tab(char **tb);
void		test_set(char **name_var, t_list_var **buffer,
			 t_list_var **list_var);
void		test_alias(char **name_var, t_list_var **alias_buf,
			   t_list_var **alias);
void		test_unset(char **name_var, t_list_var **buffer);
int		my_unsetenv(char **value, char **env);
int		my_set(char **av, int *tb);
int		my_echo(char **str, char **env, int *tb);
int		env_funct(char **av, char **env, int *tb);
int		my_setenv(char **value, char **env, int *tb);
int		exec_cd(char **av, char **env, int *tb);
int		my_unset(char **av);
int		return_good_return_value(int stat_val);
void		fils_fonction(t_commande *cmd, t_shell *shell,
			      int *tb, char *str);
int		exit_func(char **av, char **env);
int		check_type(char *name, t_shell *shell);
int		exec_with_fork(t_commande *cmd, t_shell *shell,
			       int *tb, char *str);
int		exec_builtin(t_commande *cmd, t_shell *shell, int *tb);
char		**str_to_wordtab_parse_rc(char *str);
struct passwd	*xgetpwuid(int uid);
char		*real_name();
int		my_strcmp(char *s1, char *s2);
void		change_env(char **env, int *tb);
void		change_env_last(char **env, int *tb);
int		count_param(char **av);
int		change_dir(char **av, char **env, int *tb);
int		write_error(char *to_write, char *param);
int		my_setenv(char **value, char **env, int *tb);
int		my_getnbr(char *str);
char		*my_get_env(char *to_find, char **env);
void		free_graph(t_hach_bin *tb);
int		go_end_env(char **env);
char		*get_name_env(char *value);
int		which_type(char *buf, int pos, int *begin);
int		is_dir(char *buf, char *buf2, int pos, int begin);
void		put_in_buf(char *buf, char *dest, int begin);
void		completion(int *i, int *pos, char *buf);
void		exit_buf(char *buf, char *cha);
void		clr_screen(char *buf, int i, int pos);
char		*while_cha(char *cha, char *str, int *pos, int *i);
int		parse_rc(t_shell *shell);
int		size_env(char **av);
void		free_graph_parseur(t_commande *cmd);
char		*func_old_pwd(int test);
char		*my_strstr(char *str, char *to_find);
int		test_balise_motd(char *str, char *balise);
char		*parse_prompt(char *prompt);
int		open_motd();
int		my_strcmp_star(char *s1, char *s2);
char		*get_name_env(char *value);
int		my_strcmp_star(char *s1, char *s2);
char		*cmp_star(char *s1, char *s2, int pos);
char		**my_str_to_wordtab_star(char *s);
char		*path_motd();
int		check_good_balise(int fd);
int		my_strlen_star(char *str);
void		update_var_with_ret(int ret);
char		*my_get_var(char *to_find, t_list_var *variable);
int		aff_motd(t_shell *shell);
int		xfree(void *ptr);
int		xclose(int fd);
int		xopen(char *pathname, int flags);
void		free_var(t_list_var *list);
int		check_if_alias(char *name, t_list_var *alias);
void		*xrealloc(void *ptr, int size);
void		(*xsignal(int sig, void (*func)(int)))(int);
int		count_word_parse(char *str);
int		invalid_cmd_why(t_commande *cmd, int *d);
int		set_group(int returnfork, int sauv);
int		check_if_not_redirection(char *str);

#endif
