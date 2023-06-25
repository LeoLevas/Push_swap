# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:00:51 by llevasse          #+#    #+#              #
#    Updated: 2023/06/25 14:33:10 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			= -Wall -Wextra -Werror -g -I $(INC_DIR)

FILES			= 	srcs/check_int.c \
					srcs/chunk_b.c \
					srcs/chunk.c \
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


INC_DIR			= includes/

LIBFT			= libft/libft.a

OBJS			= ${FILES:.c=.o} ${LIBFT_FILES:.c=.o}

NAME			= push_swap

%.o:			%.c $(LIBFT) Makefile includes/push_swap.h
					cc ${FLAGS} -c $< -o ${<:.c=.o}
				
${NAME}:		libft ${OBJS} $(NAME) includes/push_swap.h Makefile
					cc $(FLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT)::
				@make -sC libft

all:			${NAME}

clean:			
					rm -f ${OBJS}

fclean:			clean
					rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
