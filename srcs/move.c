/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:46:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/11 14:18:27 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(struct s_int_list *lst)
{
	swap(lst->lst_a);
}

void	ft_sb(struct s_int_list *lst)
{
	swap(lst->lst_b);
}

void	ft_ss(struct s_int_list *lst)
{
	swap(lst->lst_a);
	swap(lst->lst_b);
}

void	ft_pa(struct s_int_list *lst)
{
	push(lst->lst_a, lst->lst_b, &lst->len_a, &lst->len_b);
}

void	ft_pb(struct s_int_list *lst)
{
	push(lst->lst_b, lst->lst_a, &lst->len_b, &lst->len_a);
}

void	ft_ra(struct s_int_list *lst)
{
	rotate(lst->lst_a, lst->len_a);
}

void	ft_rb(struct s_int_list *lst)
{
	rotate(lst->lst_b, lst->len_b);
}

void	ft_rr(struct s_int_list *lst)
{
	ft_ra(lst);
	ft_rb(lst);
}

void	ft_rra(struct s_int_list *lst)
{
	reverse_rotate(lst->lst_a, &lst->len_a);
}

void	ft_rrb(struct s_int_list *lst)
{
	reverse_rotate(lst->lst_b, &lst->len_b);
}

void	ft_rrr(struct s_int_list *lst)
{
	ft_rra(lst);
	ft_rrb(lst);
}
