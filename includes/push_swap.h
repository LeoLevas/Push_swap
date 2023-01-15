/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:51:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/15 13:46:48 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

typedef struct s_int_list
{
	int				*lst_a;
	int				*lst_b;
	int				len_a;
	int				len_b;
	int				*ptr_a;
	int				*ptr_b;
	int				max_len;
}	t_int_list;

typedef struct s_chunk
{
	int	min;
	int	max;
	int	index;
	int	hold_1;
	int	hold_2;
	int	length;
	int	nbr_chunk;
}	t_chunk;

/* push_swap_utils.c */

int					is_stack_sorted(t_int_list *lst);
int					is_duplicate(int *lst, int len);
void				set_zero(int *lst, int len);
int					*get_list(t_int_list *lst, int argc, char *argv[]);
int					is_char_only_digits(char *str);
void				print_list(t_int_list *lst, int all);
int					get_elem_position_in_sort(t_int_list *lst, int temp);
int					get_highest_elem_pos(int *lst, int len);
int					get_highest_elem(int *lst, int len);
int					get_lowest_elem_pos(int *lst, int len);
int					get_lowest_elem(int *lst, int len);
int					get_range(int min, int max);

/* {func name}.c */

void				swap(int *lst);
void				push(int *lst_1, int *lst_2, int *len_1, int *len_2);
void				rotate(int *lst, int len);
void				reverse_rotate(int *lst, int len);

/* move.c */

void				ft_sa(t_int_list *lst);
void				ft_sb(t_int_list *lst);
void				ft_ss(t_int_list *lst);
void				ft_pa(t_int_list *lst);
void				ft_pb(t_int_list *lst);
void				ft_ra(t_int_list *lst);
void				ft_rb(t_int_list *lst);
void				ft_rr(t_int_list *lst);
void				ft_rra(t_int_list *lst);
void				ft_rrb(t_int_list *lst);
void				ft_rrr(t_int_list *lst);

/* sort.c */

void				less_three_sort(t_int_list *lst);
void				less_five_sort(t_int_list *lst);
void				big_sort(t_int_list *lst);
void				check_push_b(t_int_list *lst);

/* init.c */

t_int_list			*init_list(int argc, char *argv[]);
int					kill_lst(t_int_list *lst);

/* chunk.c */

int					is_in_chunk(t_chunk *chunk, int nbr);
int					get_int_pos_in_list(t_int_list *lst, int nbr);
int					get_hold_best_rotate(t_int_list *lst, int nbr);
void				rotate_holds(t_int_list *lst, int hold_1, int hold_2);
void				rotate_one_hold(t_int_list *lst, int hold);
int					need_search_chunk(t_int_list *lst, t_chunk *chunk);
int					nbr_chunk(t_int_list *lst);
t_chunk				*init_chunk(t_int_list *lst);

/* chunk_b.c */

int					get_best_pos_in_b(t_int_list *lst);
int					get_int_pos_in_list_b(t_int_list *lst, int nbr);
int					get_int_best_rotate_b(t_int_list *lst, int nbr);
void				rotate_one_hold_b(t_int_list *lst, int hold);
void				rotate_best_pos(t_int_list *lst);
void				get_highest_to_top(t_int_list *lst);

#endif
