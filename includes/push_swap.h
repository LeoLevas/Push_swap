/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:51:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/28 08:37:18 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifndef CAN_PRINT
#  define CAN_PRINT 1
# endif

typedef struct s_int_list
{
	int				*lst_a;
	int				*lst_b;
	int				len_a;
	int				len_b;
	int				max_len;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				sa;
	int				sb;
	int				ss;
}	t_int_list;

void				print_list(t_int_list *lst);
void				print_inst(t_int_list *lst);
void			    init_inst_count(t_int_list *lst);

/* push_swap_utils.c */

int					is_stack_sorted(t_int_list *lst);
int					is_duplicate(int *lst, int len);
void				set_zero(int *lst, int len);
int					is_char_only_digits(char *str);
int					get_range(int min, int max);

/* get_elem.c */

int					get_elem_position_in_sort(t_int_list *lst, int temp);
int					get_highest_elem(int *lst, int len);
int					get_lowest_elem(int *lst, int len);

/* {func name}.c */

void				swap(int *lst);
void				push(int *lst_1, int *lst_2, int *len_1, int *len_2);
void				rotate(int *lst, int len);
void				reverse_rotate(int *lst, int len);

/* ft_swap.c */

void				ft_sa(t_int_list *lst, t_int_list *lst_simple);
void				ft_sb(t_int_list *lst, t_int_list *lst_simple);
void				ft_ss(t_int_list *lst, t_int_list *lst_simple);

/* ft_push.c */

void				ft_pa(t_int_list *lst, t_int_list *lst_sim);
void				ft_pb(t_int_list *lst, t_int_list *lst_sim);

/* ft_rotate */

void				ft_ra(t_int_list *lst, t_int_list *lst_simple);
void				ft_rb(t_int_list *lst, t_int_list *lst_simple);
void				ft_rr(t_int_list *lst, t_int_list *lst_simple);

/* ft_reverse_rotate.c */

void				ft_rra(t_int_list *lst, t_int_list *lst_simple);
void				ft_rrb(t_int_list *lst, t_int_list *lst_simple);
void				ft_rrr(t_int_list *lst, t_int_list *lst_simple);

/* sort.c */

void				less_three_sort(t_int_list *lst);
void				less_five_sort(t_int_list *lst);
void				big_sort(t_int_list *lst, t_int_list *lst_simple);

/* init.c */

t_int_list			*init_list(int argc, char *argv[]);
int					*get_list_split(t_int_list *lst, int *argc, char **tab);
int					*get_list(t_int_list *lst, int *argc, char *argv[]);
void				kill_lst(t_int_list *lst, t_int_list *lst_copy);

/* init_simple */

void				simple_lst(t_int_list *lst, t_int_list *lst_simple);
int					get_int_pos_in_list(int *lst, int len, int nbr);

/* check_int.c */

long long			ft_atoi_long_long(const char *str);
int					ft_isspace(char c);

/* significant_digit.c */

int					get_lsd(int *lst, int len, int digit);
int					get_msd(int *lst, int len, int digit);

#endif
