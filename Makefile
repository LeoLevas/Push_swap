# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:00:51 by llevasse          #+#    #+#              #
#    Updated: 2023/01/16 12:43:59 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			= -Wall -Wextra -Werror -fsanitize=address

FILES			= srcs/*.c

LIBFT_FILES		= libft/ft_printf.c libft/ft_printf_utils.c libft/ft_atoi.c libft/ft_striteri.c libft/ft_bzero.c libft/ft_strjoin.c libft/ft_calloc.c libft/ft_strlcat.c libft/ft_isalnum.c libft/ft_memchr.c libft/ft_strlcpy.c libft/ft_isalpha.c libft/ft_memcmp.c libft/ft_strlen.c libft/ft_isascii.c libft/ft_memcpy.c libft/ft_strmapi.c libft/ft_isdigit.c libft/ft_memmove.c libft/ft_strncmp.c libft/ft_isprint.c libft/ft_memset.c libft/ft_strnstr.c libft/ft_itoa.c libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_strrchr.c libft/ft_putendl_fd.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_putstr_fd.c libft/ft_tolower.c libft/ft_split.c libft/ft_toupper.c libft/ft_strchr.c libft/ft_strdup.c

OBJS			= ${FILES:.c=.o} ${LIBFT_FILES:.c=.o}

NAME			= push_swap.a

USEFUL_FILES	= srcs/push_swap_utils.c libft/ft_printf.c libft/ft_printf_utils.c \
					libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strlen.c libft/ft_itoa.c \
					libft/ft_tolower.c libft/ft_memset.c libft/ft_atoi.c

EXECUTABLE	:= main

VAR				= 12 9 17 33 60 66 58 26 87 86 5 52 59 27 45 25 69 15 79 40 37 61 72 11 50 38 82 24 95 71 34 90 7 98 19 20 28 65 81 55 29 31 18 3 4 46 97 42 0 96 53 48 78 23 100 47 92 88 13 89 56 22 77 93 94 49 16 68 70 64 57 85 80 54 63 21 10 2 83 43 39 51 8 84 73 76 35 1 41 6 30 67 75 36 99 14 74 91 44 62

.c.o:
					gcc ${FLAGS} -c $< -o ${<:.c=.o}
				
${NAME}:		${OBJS}
					cd libft; make libft.a; cd ..; ar rcs ${NAME} ${OBJS}

all:			${NAME}

clean:			
					rm -f ${OBJS}

fclean:			clean
					rm -f ${NAME}

re:				fclean all

alldebug:	bin/$(EXECUTABLE)

run: cleandebug alldebug
	clear
	./bin/$(EXECUTABLE) ${VAR}

run_vs_code: cleandebug alldebug
	clear
	./bin/$(EXECUTABLE)


bin/$(EXECUTABLE): ${FILES} ${LIBFT_FILES}
	gcc ${FLAGS} -ggdb $^ -o $@ 

cleandebug:
	-rm bin/*

.PHONY:			all clean fclean re
