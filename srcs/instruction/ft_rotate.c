/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:42:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/27 22:37:32 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_int_list *lst, t_int_list *lst_simple)
{
	rotate(lst->lst_a, lst->len_a);
	if (lst_simple)
		rotate(lst_simple->lst_a, lst_simple->len_a);
	lst->ra++;
	if (!CAN_PRINT)
		print_inst(lst);
	else
		ft_printf("ra\n");
}

void	ft_rb(t_int_list *lst, t_int_list *lst_simple)
{
	rotate(lst->lst_b, lst->len_b);
	if (lst_simple)
		rotate(lst_simple->lst_b, lst_simple->len_b);
	lst->rb++;
	if (!CAN_PRINT)
		print_inst(lst);
	else
		ft_printf("rb\n");
}

void	ft_rr(t_int_list *lst, t_int_list *lst_simple)
{
	rotate(lst->lst_a, lst->len_a);
	if (lst_simple)
		rotate(lst_simple->lst_a, lst_simple->len_a);
	rotate(lst->lst_b, lst->len_b);
	if (lst_simple)
		rotate(lst_simple->lst_b, lst_simple->len_b);
	lst->rr++;
	if (!CAN_PRINT)
		print_inst(lst);
	else
		ft_printf("rr\n");
}
