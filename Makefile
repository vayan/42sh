##
## Makefile for rt in /home/consta_m/prog/rt
## 
## Made by maxime constantinian
## Login   <consta_m@epitech.net>
## 
## Started on  Mon Feb 28 14:08:05 2011 maxime constantinian
## Last update Tue Apr 26 22:27:17 2011 justin pugeat
##

CC=     cc

NAME=   42sh

CFLAGS= -I./include -W -Wall -O3

LDFLAGS= -lcurses

OBJ_DIR= obj

RM=     rm -f

SRC=    src/main.c \
	src/termcap.c \
	src/cpy_env.c \
	src/str_copy_nalloc.c \
	src/xmalloc.c
OBJ=    $(subst src/, $(OBJ_DIR)/, $(SRC))

OBJ:=   $(OBJ:.c=.o)

$(NAME):	$(OBJ)
		@$(CC) $^ $(LDFLAGS) -o $@
		# @echo -e "\E[33;36m[CC]  creation de $@.\E[33;39m"

all:    	$(NAME)

$(OBJ_DIR)/%.o: src/%.c
		@$(CC) -c $< $(INCLUDE) $(CFLAGS) -o $@
		# @echo -e "\E[33;32m[OBJ] creation de $@\E[33;39m"

clean:
	@$(RM) $(OBJ_DIR)/*.o
	# @echo -e "\E[33;31m[RM]  suppression des fichiers objets...\E[33;39m"

fclean: clean
	@$(RM) $(NAME)
	# @echo -e "\E[33;38m[RM]  suppresion de l'executable $(NAME).\E[33;39m"

re:     fclean all