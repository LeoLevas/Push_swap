# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:00:51 by llevasse          #+#    #+#              #
#    Updated: 2023/01/20 16:16:49 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			= -Wall -Wextra -Werror

FILES			= 	srcs/check_int.c \
					srcs/chunk_b.c \
					srcs/chunk.c \
					srcs/do_not_push.c \
					srcs/ft_push.c \
					srcs/ft_reverse_rotate.c \
					srcs/ft_rotate.c \
					srcs/ft_swap.c \
					srcs/get_elem.c \
					srcs/holds.c \
					srcs/init.c \
					srcs/push.c \
					srcs/push_swap.c \
					srcs/push_swap_utils.c \
					srcs/reverse_rotate.c \
					srcs/rotate_best_pos.c \
					srcs/rotate.c \
					srcs/sort.c \
					srcs/swap.c \
					srcs/significant_digit.c


LIBFT_FILES		= libft/ft_printf.c libft/ft_printf_utils.c libft/ft_atoi.c libft/ft_striteri.c libft/ft_bzero.c libft/ft_strjoin.c libft/ft_calloc.c libft/ft_strlcat.c libft/ft_isalnum.c libft/ft_memchr.c libft/ft_strlcpy.c libft/ft_isalpha.c libft/ft_memcmp.c libft/ft_strlen.c libft/ft_isascii.c libft/ft_memcpy.c libft/ft_strmapi.c libft/ft_isdigit.c libft/ft_memmove.c libft/ft_strncmp.c libft/ft_isprint.c libft/ft_memset.c libft/ft_strnstr.c libft/ft_itoa.c libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_strrchr.c libft/ft_putendl_fd.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_putstr_fd.c libft/ft_tolower.c libft/ft_split.c libft/ft_toupper.c libft/ft_strchr.c libft/ft_strdup.c

OBJS			= ${FILES:.c=.o} ${LIBFT_FILES:.c=.o}

NAME			= push_swap.a

USEFUL_FILES	= srcs/push_swap_utils.c libft/ft_printf.c libft/ft_printf_utils.c \
					libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strlen.c libft/ft_itoa.c \
					libft/ft_tolower.c libft/ft_memset.c libft/ft_atoi.c

EXECUTABLE		:= push_swap

VAR				= 87 60 96 94 47 17 74 31 19 12 36 20 92 73 58 35 37 24 48 49 53 30 18 72 79 75 28 22 44 45 81 82 59 64 43 16 52 95 98 67 6 50 13 56 33 21 40 70 11 2 85 27 83 93 97 8 34 66 23 99 0 32 84 41 90 10 80 71 89 86 88 68 26 51 14 5 4 63 55 91 77 57 25 29 7 61 39 65 42 78 76 1 9 15 38 3 69 62 46 54

.c.o:
					gcc ${FLAGS} -c $< -o ${<:.c=.o}
				
${NAME}:		${OBJS}
					cd libft; make libft.a; cd ..; ar rcs ${NAME} ${OBJS} ; gcc ${NAME} -o ${EXECUTABLE}

all:			${NAME}

clean:			
					rm -f ${OBJS}

fclean:			clean
					rm -f ${NAME} ${EXECUTABLE}

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
