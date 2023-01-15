/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:24:28 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/15 11:08:38 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_chunk	*init_chunk(t_int_list *lst)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);

	chunk->max = get_highest_elem(lst->lst_a, lst->len_a);
	chunk->min = get_lowest_elem(lst->lst_a, lst->len_a);
	chunk->length = 20;
	chunk->nbr_chunk = lst->max_len / 20;
	chunk->index = 1;

	return (chunk);
}

int	is_in_chunk(t_int_list *lst, t_chunk *chunk, int nbr)
{
	nbr = *lst->lst_a;
	if (nbr >= chunk->min && nbr < (chunk->min + chunk->length))
		return (1);
	return (0);
}

int	nbr_chunk(t_int_list *lst)
{
	return (lst->max_len / 20);
}

int	need_search_chunk(t_int_list *lst, t_chunk *chunk)
{
	int	i;
	int	nbr;

	i = 0;

	while (i < lst->len_a)
	{
		nbr = *(lst->lst_a + i);
		if (nbr >= chunk->min && nbr < (chunk->min + chunk->length))
			return (1);
		i++;
	}
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
