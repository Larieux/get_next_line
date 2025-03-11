# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 12:42:11 by mlarieux          #+#    #+#              #
#    Updated: 2025/03/11 12:42:13 by mlarieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	get_next_line_utils.c \
		get_next_line.c \
		tester_get_next_line.c

SRC_DIR := src
INCDIR := include
OBJ_DIR := obj
BIN_DIR := .

VPATH = $(SRC_DIR)

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

CPPFLAGS := -I$(INCDIR)
CFLAGS := -Wall -Wextra -Werror

NAME = $(BIN_DIR)/get_next_line

all : $(NAME)

$(NAME) : $(OBJ) | $(BIN_DIR)
	$(CC) $^ -o $@ $(CFLAGS)

$(BIN_DIR) $(OBJ_DIR) :
	mkdir $@

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) -rv $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony : all clean fclean re