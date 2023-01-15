# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 17:00:51 by llevasse          #+#    #+#              #
#    Updated: 2023/01/15 14:22:23 by llevasse         ###   ########.fr        #
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

VAR				= 207 -418 -880 191 -226 709 128 841 538 184 18 -83 697 -32 239 -120 -648 728 662 -534 691 -69 -848 -928 -285 -626 712 323 353 -465 -623 -689 959 -466 -677 -740 -147 -403 893 -393 222 682 -683 550 -460 111 -634 -514 984 -877 -603 -66 -786 28 -507 -496 483 478 -852 763 -422 -261 -149 -214 -633 132 510 860 -591 901 272 -419 -282 489 983 -362 -472 -992 40 -900 -304 -490 27 619 422 -133 133 -480 -702 590 -564 -826 500 -369 52 -498 -328 909 356 981 310 -43 459 -661 -971 -401 -232 -629 -678 -483 -884 -327 -866 -870 -635 -284 -221 492 591 432 546 332 411 669 663 -615 791 858 -708 -658 -732 269 922 496 851 -161 44 679 -686 205 425 -804 579 681 808 -38 472 -407 349 -670 -406 -763 -189 161 247 -780 613 520 -168 404 -606 -916 -89 337 399 960 617 -259 -631 -373 -400 304 -587 400 524 -923 -388 530 145 151 695 -503 885 608 -743 -868 976 305 -19 904 -860 677 -570 -345 163 651 415 277 502 954 622 -703 450 -445 -155 279 -379 -312 484 -478 -952 -808 -776 -488 -963 537 285 833 226 -384 644 -939 105 759 659 -535 -29 -819 -710 -718 -915 -424 892 -153 383 -333 806 385 793 -788 723 -782 321 72 418 -269 -630 -37 908 693 -834 -145 685 -51 363 -256 -871 251 556 907 470 917 336 -396 942 812 -969 767 572 501 19 71 43 -493 -236 531 -158 -188 852 518 456 -86 155 722 -941 12 -391 141 711 100 990 437 -681 322 554 -425 -906 -494 688 355 974 513 545 0 807 233 561 536 -893 -774 -598 836 -586 -152 -806 -528 743 314 -225 -180 -830 -733 -559 62 879 -983 941 -896 -685 257 -476 964 -171 124 -62 -813 449 -736 -395 231 -339 -968 178 365 -762 566 947 108 -49 466 -290 -753 217 -584 64 553 -353 22 440 -248 975 698 264 -336 -288 487 -555 -183 59 925 517 -295 148 -625 -453 200 943 3 455 -996 25 -50 -690 -861 -783 -801 726 -524 460 -608 827 -444 -208 -415 -997 -552 539 -329 523 387 465 -636 -58 410 -793 814 -873 -919 75 242 -132 -455 -46 -621 -94 107 -294 900 -692 -538 -768 -30 -532 838 60 -446 -91 938 623 17 464 -553 963 758 792 634 81 946 -324 -430 -241 266 696 -26 -77 -255 -698 -224 256 452 -443 -981 -128 -501 391 334 -159 250 -34 987 950 -215 -724 -252 866 -886 -397 660 262 275 -990 826 955 -558 875 -892 508 760 -163 -620 830 -728 441 944 -599 -489 -491 346 -356 -44 -343 781 991 270 876 291 -321 797 865 187

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
