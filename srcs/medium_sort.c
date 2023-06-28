/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:18:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/28 23:33:21 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_lowest(t_int_list *lst);

void	less_five_sort(t_int_list *lst)
{
	while (lst->len_a > 3)
		push_lowest(lst);
	less_three_sort(lst);
	while (lst->len_b > 0)
		ft_pa(lst, NULL);
}

void	push_lowest(t_int_list *lst)
{
	int	pos;
	int	lowest;

	lowest = get_lowest_elem(lst->lst_a, lst->len_a);
	pos = get_index(lst->lst_a, lst->len_a, lowest);
	if (pos <= (lst->len_a / 2) && pos != lst->len_a)
	{
		while (*lst->lst_a != lowest)
			ft_ra(lst, NULL);
	}
	if (pos > (lst->len_a / 2))
	{
		while (*lst->lst_a != lowest)
			ft_rra(lst, NULL);
	}
	ft_pb(lst, NULL);
}
