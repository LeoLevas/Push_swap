/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:40:43 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/27 22:37:44 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_int_list *lst, t_int_list *lst_simple)
{
	swap(lst->lst_a);
	if (lst_simple)
		swap(lst_simple->lst_a);
	lst->sa++;
	if (!CAN_PRINT)
		print_inst(lst);
	else
		ft_printf("sa\n");
}

void	ft_sb(t_int_list *lst, t_int_list *lst_simple)
{
	swap(lst->lst_b);
	if (lst_simple)
		swap(lst_simple->lst_b);
	lst->sb++;
	if (!CAN_PRINT)
		print_inst(lst);
	else
		ft_printf("sb\n");
}

void	ft_ss(t_int_list *lst, t_int_list *lst_simple)
{
	swap(lst->lst_a);
	swap(lst->lst_b);
	if (lst_simple)
	{
		swap(lst_simple->lst_a);
		swap(lst_simple->lst_b);
	}
	lst->ss++;
	if (!CAN_PRINT)
		print_inst(lst);
	else
		ft_printf("ss\n");
}
