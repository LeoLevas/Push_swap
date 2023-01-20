/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:24:28 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/20 16:47:39 by llevasse         ###   ########.fr       */
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
	chunk->nbr_chunk = (get_range(chunk->min, chunk->max) / 20) + 1;
	chunk->index = 1;
	return (chunk);
}

int	is_in_chunk(t_chunk *chunk, int nbr)
{
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
	while (*(lst->lst_a + i) != nbr && i < lst->len_a)
		i++;
	if (*(lst->lst_a + i) == nbr)
		return (i);
	return (-1);
}
