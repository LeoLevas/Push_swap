/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:46:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/11 15:20:13 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(struct s_int_list *lst)
{
	swap(lst->lst_a);
	ft_printf("sa\n");
}

void	ft_sb(struct s_int_list *lst)
{
	swap(lst->lst_b);
	ft_printf("sb\n");
}

void	ft_ss(struct s_int_list *lst)
{
	swap(lst->lst_a);
	swap(lst->lst_b);
	ft_printf("ss\n");
}

void	ft_pa(struct s_int_list *lst)
{
	push(lst->lst_a, lst->lst_b, &lst->len_a, &lst->len_b);
	ft_printf("pa\n");
}

void	ft_pb(struct s_int_list *lst)
{
	push(lst->lst_b, lst->lst_a, &lst->len_b, &lst->len_a);
	ft_printf("pb\n");
}

void	ft_ra(struct s_int_list *lst)
{
	rotate(lst->lst_a, lst->len_a);
	ft_printf("ra\n");
}

void	ft_rb(struct s_int_list *lst)
{
	rotate(lst->lst_b, lst->len_b);
	ft_printf("rb\n");
}

void	ft_rr(struct s_int_list *lst)
{
	rotate(lst->lst_a, lst->len_a);
	rotate(lst->lst_b, lst->len_b);
	ft_printf("rr\n");
}

void	ft_rra(struct s_int_list *lst)
{
	reverse_rotate(lst->lst_a, lst->len_a);
	ft_printf("rra\n");
}

void	ft_rrb(struct s_int_list *lst)
{
	reverse_rotate(lst->lst_b, lst->len_b);
	ft_printf("rrb\n");
}

void	ft_rrr(struct s_int_list *lst)
{
	reverse_rotate(lst->lst_a, lst->len_a);
	reverse_rotate(lst->lst_b, lst->len_b);
	ft_printf("rrr\n");
}
