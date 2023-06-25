/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:08:17 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/25 21:06:23 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simple_lst(t_int_list *lst, t_int_list *lst_simple)
{
	int	i;
	int	lowest;
	int	highest;
	int	pos;
	int	*lst_a;

	lst_a = lst->lst_a;
	lowest = get_lowest_elem(lst_a, lst->max_len);
	highest = get_highest_elem(lst_a, lst->max_len);
	i = 0;
	pos = get_int_pos_in_list(lst_a, lst->max_len, lowest++);
	while (i <= lst->max_len && lowest <= highest)
	{
		*(lst_simple->lst_a + pos) = i++;
		pos = -1;
		while (pos == -1)
		{
			pos = get_int_pos_in_list(lst_a, lst->max_len, lowest++);
			if (lowest - 1 == highest)
				*(lst_simple->lst_a + pos) = i;
		}
	}
}

int	get_int_pos_in_list(int *lst, int len, int nbr)
{
	int	i;

	i = 0;
	while (*(lst + i) != nbr && i < len)
		i++;
	if (*(lst + i) == nbr)
		return (i);
	return (-1);
}
