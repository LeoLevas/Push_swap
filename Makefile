# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:00:51 by llevasse          #+#    #+#              #
#    Updated: 2023/01/25 18:20:40 by llevasse         ###   ########.fr        #
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
					srcs/init_simple.c \
					srcs/significant_digit.c


LIBFT_FILES		= libft/ft_printf.c libft/ft_printf_utils.c libft/ft_atoi.c libft/ft_striteri.c libft/ft_bzero.c libft/ft_strjoin.c libft/ft_calloc.c libft/ft_strlcat.c libft/ft_isalnum.c libft/ft_memchr.c libft/ft_strlcpy.c libft/ft_isalpha.c libft/ft_memcmp.c libft/ft_strlen.c libft/ft_isascii.c libft/ft_memcpy.c libft/ft_strmapi.c libft/ft_isdigit.c libft/ft_memmove.c libft/ft_strncmp.c libft/ft_isprint.c libft/ft_memset.c libft/ft_strnstr.c libft/ft_itoa.c libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_strrchr.c libft/ft_putendl_fd.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_putstr_fd.c libft/ft_tolower.c libft/ft_split.c libft/ft_toupper.c libft/ft_strchr.c libft/ft_strdup.c

OBJS			= ${FILES:.c=.o} ${LIBFT_FILES:.c=.o}

NAME			= push_swap.a

USEFUL_FILES	= srcs/push_swap_utils.c libft/ft_printf.c libft/ft_printf_utils.c \
					libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strlen.c libft/ft_itoa.c \
					libft/ft_tolower.c libft/ft_memset.c libft/ft_atoi.c

EXECUTABLE		:= push_swap

VAR				= 45 41 -34 -49 -4 -77 75 51 -80 43 84 -88 52 -25 99 28 -18 19 54 10 -20 22 -12 -37 -44 -30 -94 60 -33 25 6 66 -11 -9 -74 58 31 -68 57 62 48 67 -17 74 -58 50 -93 -19 -47 -82 21 17 81 -86 70 -62 -24 -53 -13 -85 -36 -71 -32 5 4 13 77 82 -52 69 -22 30 34 27 -92 -64 2 33 93 -28 -39 -63 -61 -29 -54 68 -35 49 55 -1 95 -70 0 59 35 -41 18 -50 -55 -89

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
