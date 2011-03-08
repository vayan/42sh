##
## Makefile for rt in /home/consta_m/prog/rt
## 
## Made by maxime constantinian
## Login   <consta_m@epitech.net>
## 
## Started on  Mon Feb 28 14:08:05 2011 maxime constantinian
## Last update Tue Mar  8 11:46:52 2011 maxime constantinian
##

CC=     cc

NAME=   42sh

CFLAGS= -I./include -W -Wall -pedantic -ansi -O3

LDFLAGS= 

OBJ_DIR= obj

RM=     rm -f

SRC=    src/main.c

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