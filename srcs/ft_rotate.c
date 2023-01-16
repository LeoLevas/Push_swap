/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:42:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/16 11:42:14 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_int_list *lst)
{
	rotate(lst->lst_a, lst->len_a);
	ft_printf("ra\n");
}

void	ft_rb(t_int_list *lst)
{
	rotate(lst->lst_b, lst->len_b);
	ft_printf("rb\n");
}

void	ft_rr(t_int_list *lst)
{
	rotate(lst->lst_a, lst->len_a);
	rotate(lst->lst_b, lst->len_b);
	ft_printf("rr\n");
}
