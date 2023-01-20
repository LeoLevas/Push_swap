/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:46:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/20 17:38:09 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_int_list *lst)
{
	if (!lst->len_b)
		return ;
	push(lst->lst_a, lst->lst_b, &lst->len_a, &lst->len_b);
	lst->len_b -= 1;
	ft_printf("pa\n");
}

void	ft_pb(t_int_list *lst)
{
	if (!lst->len_a)
		return ;
	push(lst->lst_b, lst->lst_a, &lst->len_b, &lst->len_a);
	lst->len_a -= 1;
	ft_printf("pb\n");
}
