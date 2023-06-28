/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:39:12 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/27 22:37:24 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_int_list *lst, t_int_list *lst_simple)
{
	reverse_rotate(lst->lst_a, lst->len_a);
	if (lst_simple)
		reverse_rotate(lst_simple->lst_a, lst_simple->len_a);
	lst->rra++;
	if (!CAN_PRINT)
		print_inst(lst);
	else
		ft_printf("rra\n");
}

void	ft_rrb(t_int_list *lst, t_int_list *lst_simple)
{
	reverse_rotate(lst->lst_b, lst->len_b);
	if (lst_simple)
		reverse_rotate(lst_simple->lst_b, lst_simple->len_b);
	lst->rrb++;
	if (!CAN_PRINT)
		print_inst(lst);
	else
		ft_printf("rrb\n");
}

void	ft_rrr(t_int_list *lst, t_int_list *lst_simple)
{
	reverse_rotate(lst->lst_a, lst->len_a);
	reverse_rotate(lst->lst_b, lst->len_b);
	if (lst_simple)
		reverse_rotate(lst_simple->lst_a, lst_simple->len_a);
	if (lst_simple)
		reverse_rotate(lst_simple->lst_b, lst_simple->len_b);
	lst->rrr++;
	if (!CAN_PRINT)
		print_inst(lst);
	else
		ft_printf("rrr\n");
}
