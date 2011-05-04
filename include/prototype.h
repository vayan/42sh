/*
** prototype.h for  in /home/consta_m/prog/42sh
** 
** Made by maxime constantinian
** Login   <consta_m@epitech.net>
** 
** Started on  Wed May  4 11:14:59 2011 maxime constantinian
** Last update Wed May  4 11:28:12 2011 maxime constantinian
*/

#ifndef		PROTYPE_H__
# define	PROTYPE_H__

char		*my_strcopynalloc(char *str);
char		*my_strcopynalloc_gen(char *str, int len);
void		exec_type_cmd(t_commande *cmd, t_shell *shell);
char		*my_get_env(char *str, char **env);
void		*xmalloc(int size);
char		**str_to_wordtab(char *str);

#endif
