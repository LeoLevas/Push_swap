/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:39:12 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/16 11:42:18 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_int_list *lst)
{
	reverse_rotate(lst->lst_a, lst->len_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_int_list *lst)
{
	reverse_rotate(lst->lst_b, lst->len_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_int_list *lst)
{
	reverse_rotate(lst->lst_a, lst->len_a);
	reverse_rotate(lst->lst_b, lst->len_b);
	ft_printf("rrr\n");
}
