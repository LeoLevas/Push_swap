/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:40:43 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/16 11:40:52 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_int_list *lst)
{
	swap(lst->lst_a);
	ft_printf("sa\n");
}

void	ft_sb(t_int_list *lst)
{
	swap(lst->lst_b);
	ft_printf("sb\n");
}

void	ft_ss(t_int_list *lst)
{
	swap(lst->lst_a);
	swap(lst->lst_b);
	ft_printf("ss\n");
}
