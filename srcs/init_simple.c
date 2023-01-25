/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:08:17 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/25 18:19:37 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simple_lst(t_int_list *lst, t_int_list *lst_simple)
{
	int	i;
	int	lowest;
	int	pos;

	lowest = get_lowest_elem(lst->lst_a, lst->max_len);
	i = 0;
	pos = get_int_pos_in_list(lst, lowest++);
	while (i < lst->max_len)
	{
		*(lst_simple->lst_a + pos) = i++;
		pos = -1;
		while (pos == -1)
			pos = get_int_pos_in_list(lst, lowest++);
	}
}
