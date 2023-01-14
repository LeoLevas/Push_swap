/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:24:28 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/14 14:30:44 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_in_chunk(t_int_list *lst, int nbr_chunk, int nbr)
{
	int	min;
	int	max;
	int	chunk_length;
	int	index_chunk;

	max = get_highest_elem(lst->lst_a, lst->len_a);
	min = get_lowest_elem(lst->lst_a, lst->len_a);

	chunk_length = lst->max_len / (lst->max_len / 20);
	index_chunk = 1;

	while (index_chunk < nbr_chunk && min < max)
	{
		index_chunk++;
		min += chunk_length;
	}
	if (nbr >= min && nbr < (min + chunk_length))
		return (1);
	return (0);
}

int	get_int_pos_in_list(t_int_list *lst, int nbr)
{
	int	i;

	i = 0;
	while (*(lst->lst_a + i) != nbr)
		i++;
	if (i > lst->len_a)
		return (-1);
	return (i);
}

int	get_hold_best_rotate(t_int_list *lst, int nbr)
{
	int	pos;

	pos = get_int_pos_in_list(lst, nbr);
	if (pos == -1)
		return (0);
	if (nbr == *lst->lst_a)
		return (0);
	if (pos < (lst->len_a) / 2)
		return (1);
	return (-1);
}

void	rotate_holds(t_int_list *lst, int hold_1, int hold_2)
{
	int	dist_from_start;
	int	dist_from_end;

	dist_from_start = get_int_pos_in_list(lst, hold_1);
	dist_from_end = (lst->len_a) - get_int_pos_in_list(lst, hold_2);
	if (dist_from_start < dist_from_end)
		rotate_one_hold(lst, hold_1);
	else
		rotate_one_hold(lst, hold_2);
}

void	rotate_one_hold(t_int_list *lst, int hold)
{
	while (get_hold_best_rotate(lst, hold) != 0)
	{	
		while (get_hold_best_rotate(lst, hold) == 1)
			ft_ra(lst);
		while (get_hold_best_rotate(lst, hold) == -1)
			ft_rra(lst);
	}
}
