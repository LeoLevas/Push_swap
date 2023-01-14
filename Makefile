# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:00:51 by llevasse          #+#    #+#              #
#    Updated: 2023/01/14 19:06:04 by llevasse         ###   ########.fr        #
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

VAR				= 15 7 14 68 75 55 62 31 32 53 57 2 66 52 71 1 91 45 33 17 51 59 93 56 89 39 34 90 60 77 73 10 36 81 86 63 40 49 47 61 54 48 58 44 46 16 83 20 25 9 30 88 29 85 11 24 27 18 74 35 72 21 13 4 64 28 78 23 76 96 82 6 50 3 22 98 38 5 79 37 19 42 70 97 12 67 92 94 41 65 80 0 8 84 69 26 87 43 95 99


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

run_var: cleandebug alldebug
	clear
	./bin/$(EXECUTABLE) ${VAR}

run: cleandebug alldebug
	clear
	./bin/$(EXECUTABLE)


bin/$(EXECUTABLE): ${FILES} ${LIBFT_FILES}
	gcc ${FLAGS} -ggdb $^ -o $@ 

cleandebug:
	-rm bin/*

.PHONY:			all clean fclean re
