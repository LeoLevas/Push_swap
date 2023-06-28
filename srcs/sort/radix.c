/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:10:31 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/28 23:33:26 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_int_list *lst, t_int_list *lst_simple)
{
	int		i;
	int		j;

	i = 0;
	while (!is_stack_sorted(lst_simple))
	{
		j = 0;
		while (j < lst->max_len)
		{
			if (((*lst_simple->lst_a >> i) & 1) == 1)
				ft_ra(lst, lst_simple);
			else
				ft_pb(lst, lst_simple);
			j++;
		}
		i++;
		while (lst->len_b != 0)
			ft_pa(lst, lst_simple);
	}
}
