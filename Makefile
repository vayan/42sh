##
## Makefile for rt in /home/consta_m/prog/rt
## 
## Made by maxime constantinian
## Login   <consta_m@epitech.net>
## 
## Started on  Mon Feb 28 14:08:05 2011 maxime constantinian
## Last update Sun May 22 01:40:53 2011 maxime constantinian
##

CC=     cc

NAME=   42sh

CFLAGS= -I./include -W -Wall -O3 -g

LDFLAGS= -lcurses

OBJ_DIR= obj

RM=     rm -f

SRC=    src/main.c \
	src/termcap.c \
	src/cpy_env.c \
	src/str_copy_nalloc.c \
	src/xmalloc.c \
	src/xwrite.c \
	src/buffer.c \
	src/my_strcpy.c \
	src/exec_str.c \
	src/get_touche.c \
	src/init_new_cmd.c \
	src/parseur.c \
	src/if_have_sep.c \
	src/check_and.c \
	src/check_or.c \
	src/check_pipe.c \
	src/check_commande.c \
	src/str_to_wordtab.c \
	src/my_strlen.c \
	src/create_hach.c \
	src/exec_cmd.c \
	src/isfile.c \
	src/my_get_env.c \
	src/xpipe.c \
	src/xread.c \
	src/xfork.c \
	src/xdup2.c \
	src/place_cursor.c \
	src/buffer_utils.c \
	src/buffer_histo.c \
	src/my_signal.c \
	src/recup_shell.c \
	src/check_redirection.c \
	src/str_to_wordtab_redirection.c \
	src/cur_pos.c \
	src/get_next_line.c \
	src/redirection.c \
	src/check_type.c \
	src/get_next_line.c \
	src/put_in_buf.c \
	src/completion.c \
	src/xopendir.c \
	src/my_list.c \
	src/xlstat.c \
	src/main_completion.c \
	src/while_cha.c \
	src/which_type.c \
	src/is_dir.c \
	src/my_echo.c \
	src/set_env.c \
	src/exit_func.c \
	src/func_cd.c \
	src/func_cd_other.c \
	src/utils_env.c \
	src/my_getnbr.c \
	src/concat.c \
	src/my_pwd.c \
	src/my_strcmp.c \
	src/balise_misc_rc.c \
	src/balise_time_rc.c \
	src/balise_user_rc.c \
	src/get_path_rc.c \
	src/parse_rc.c \
	src/xopen.c \
	src/xgetpwuid.c \
	src/wordtab_parse_rc.c \
	src/test_param_rc.c \
	src/modif_var.c \
	src/get_prompt.c \
	src/aff_prompt.c \
	src/free_graph.c \
	src/my_env.c \
	src/clear_screen.c \
	src/my_set.c \
	src/exec_fonction.c \
	src/exec_fork.c \
	src/free_tab.c

OBJ=    $(subst src/, $(OBJ_DIR)/, $(SRC))

OBJ:=   $(OBJ:.c=.o)

$(NAME):	$(OBJ)
		@$(CC) $^ $(LDFLAGS) -o $@
		@echo -e "\E[33;36m[CC]  creation de $@.\E[33;39m"

all:    	$(NAME)

$(OBJ_DIR)/%.o: src/%.c
		@$(CC) -c $< $(INCLUDE) $(CFLAGS) -o $@
		@echo -e "\E[33;32m[OBJ] creation de $@\E[33;39m"

clean:
	@$(RM) $(OBJ_DIR)/*.o
	@echo -e "\E[33;31m[RM]  suppression des fichiers objets...\E[33;39m"

fclean: clean
	@$(RM) $(NAME)
	@echo -e "\E[33;38m[RM]  suppresion de l'executable $(NAME).\E[33;39m"

re:     fclean all
