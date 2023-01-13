/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:51:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/13 13:56:19 by llevasse         ###   ########.fr       */
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
}	t_int_list;

int					is_stack_sorted(t_int_list *lst);
int					*get_list(int argc, char *argv[]);
int					is_char_only_digits(char *str);
int					kill_lst(t_int_list *lst);
int					is_duplicate(int *lst);
int					get_elem_position_in_sort(t_int_list *lst, int temp);
int					get_lowest_elem_pos(int *lst, int len);
int					get_highest_elem_pos(int *lst, int len);
int					get_lowest_elem(int *lst, int len);
int					get_highest_elem(int *lst, int len);

void				print_list(t_int_list *lst);
void				swap(int *lst);
void				push(int *lst_1, int *lst_2, int *len_1, int *len_2);
void				rotate(int *lst, int len);
void				reverse_rotate(int *lst, int len);
void				set_zero(int *lst, int len);

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

void				less_three_sort(t_int_list *lst);
void				less_five_sort(t_int_list *lst);


t_int_list			*init_list(int argc, char *argv[]);

#endif
