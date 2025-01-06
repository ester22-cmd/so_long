# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estferna <estferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 16:31:52 by estferna          #+#    #+#              #
#    Updated: 2025/01/04 17:24:16 by estferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME          = libft.a

CC            =    cc

CFLAGS        =    -Wall -Werror -Wextra

SRCS        = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strnstr.c ft_substr.c ft_calloc.c ft_isascii.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c get_next_line.c get_next_line_utils.c

HEADER        =    libft.h

AR            =    ar rcs

RM            =    rm -rf

OBJS        =    ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@
	${AR} ${NAME} $@

${NAME}: ${OBJS}

clean:
	${RM} ${OBJS}

fclean:    clean
	${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re