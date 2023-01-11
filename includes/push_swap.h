/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:51:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/11 16:09:42 by llevasse         ###   ########.fr       */
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

int					is_stack_sorted(struct s_int_list *lst);
int					*get_list(int argc, char *argv[]);
int					is_char_only_digits(char *str);
int					kill_lst(struct s_int_list *lst);
int					is_duplicate(int *lst);
int					get_elem_position_in_sort(struct s_int_list *lst, int temp);

void				print_list(struct s_int_list *lst);
void				swap(int *lst);
void				push(int *lst_1, int *lst_2, int *len_1, int *len_2);
void				rotate(int *lst, int len);
void				reverse_rotate(int *lst, int len);
void				set_zero(int *lst, int len);

void				ft_sa(struct s_int_list *lst);
void				ft_sb(struct s_int_list *lst);
void				ft_ss(struct s_int_list *lst);
void				ft_pa(struct s_int_list *lst);
void				ft_pb(struct s_int_list *lst);
void				ft_ra(struct s_int_list *lst);
void				ft_rb(struct s_int_list *lst);
void				ft_rr(struct s_int_list *lst);
void				ft_rra(struct s_int_list *lst);
void				ft_rrb(struct s_int_list *lst);
void				ft_rrr(struct s_int_list *lst);

void				less_three_sort(struct s_int_list *lst);
void				less_five_sort(struct s_int_list *lst);


struct s_int_list	*init_list(int argc, char *argv[]);

#endif
