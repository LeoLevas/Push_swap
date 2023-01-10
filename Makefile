# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:00:51 by llevasse          #+#    #+#              #
#    Updated: 2023/01/10 10:55:48 by llevasse         ###   ########.fr        #
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
	./bin/$(EXECUTABLE)

bin/$(EXECUTABLE): ${FILES} ${LIBFT_FILES}
	gcc ${FLAGS} -ggdb $^ -o $@ 

cleandebug:
	-rm bin/*

.PHONY:			all clean fclean re
