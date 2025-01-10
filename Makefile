# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estferna <estferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 21:18:56 by estferna          #+#    #+#              #
#    Updated: 2025/01/09 19:37:51 by estferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CC		:= cc
CFLAGS	:= -g3 -Wextra -Wall -Werror
FLAGSOMLX := -Wunreachable -code -Ofast
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft
FLAGSMLX = -ldl -lglfw -pthread -lm
HEADERS	:= -I ./include -I $(LIBMLX)/include -I./src/so_long.h 
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a
SRCS	:= ./src/main.c ./src/initimages.c ./src/initgame.c ./src/moves.c ./src/validation.c ./src/validation_utils.c ./src/validation_utils2.c ./src/utils.c

OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make all -C $(LIBFT) $(FLAGS) --no-print-directory

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME) $(FLAGSMLX)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBFT)/*.o
	@rm -rf $(LIBFT)/get_next_line/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/*.a
	@rm -rf $(LIBFT)/get_next_line/*.a

re: clean all

.PHONY: all, clean, fclean, re, libmlx