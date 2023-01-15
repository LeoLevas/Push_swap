# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:00:51 by llevasse          #+#    #+#              #
#    Updated: 2023/01/15 09:52:44 by llevasse         ###   ########.fr        #
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

VAR				= 50 84 -19 -45 71 -67 -47 14 86 28 87 62 -83 74 93 35 63 64 -96 -71 -11 -43 -91 -54 -86 75 67 22 -98 -2 -99 -80 24 -61 94 -60 34 69 -55 -92 19 57 27 -44 45 98 -18 83 -16 9 5 12 90 73 -75 43 -72 -24 -34 89 2 76 -20 -52 53 37 -38 96 21 -85 -13 6 91 16 8 92 -12 46 80 -28 -94 -53 95 49 -49 -88 -23 -87 40 58 20 41 -4 -70 65 -40 3 17 99 -90

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
