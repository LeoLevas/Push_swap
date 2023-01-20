/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:24:23 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/20 18:19:56 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



int	get_int_pos_in_list_b(t_int_list *lst, int nbr)
{
	int	i;

	i = 0;
	while (*(lst->lst_b + i) < nbr)
		i++;
	if (i > lst->len_b)
		return (-1);
	return (i);
}

int	get_int_best_rotate_b(t_int_list *lst, int nbr)
{
	int	pos;

	pos = get_int_pos_in_list_b(lst, nbr);
	if (pos == -1)
		return (0);
	if (pos == 0)
		return (0);
	if (pos < (lst->len_b) / 2)
		return (1);
	return (-1);
}

void	rotate_one_hold_b(t_int_list *lst, int hold)
{
	while (get_int_best_rotate_b(lst, hold) != 0)
	{	
		while (get_int_best_rotate_b(lst, hold) == 1)
			ft_rb(lst);
		while (get_int_best_rotate_b(lst, hold) == -1)
			ft_rrb(lst);
	}
}

int	get_best_pos_in_b(t_int_list *lst)
{
	int	i;
	int	*lst_b;
	int	len_b;
	int	nbr;

	nbr = *lst->lst_a;
	i = 0;
	lst_b = lst->lst_b;
	len_b = lst->len_b;
	i++;
	while (i < len_b)
	{
		if (*lst_b < nbr && *(lst_b + 1) > nbr)
			break ;
		i++;
		lst_b++;
	}
	if (i == len_b)
		return (0);
	return (i);
}

int	get_and_push(t_int_list *lst, t_chunk *chunk, int i)
{
	chunk->is_1_holded = 0;
	chunk->is_2_holded = 0;
	if (is_in_chunk(chunk, *(lst->lst_a + i)))
	{
		chunk->hold_1 = *(lst->lst_a + i);
		chunk->is_1_holded = 1;
	}
	i++;
	if (is_in_chunk(chunk, *(lst->lst_a + ((lst->len_a) - i))))
	{
		chunk->hold_2 = *(lst->lst_a + (lst->len_a - i));
		chunk->is_2_holded = 1;
	}
	if (chunk->is_1_holded && chunk->is_2_holded)
		rotate_holds(lst, chunk->hold_1, chunk->hold_2);
	else if (chunk->is_1_holded && !chunk->is_2_holded)
		rotate_one_hold(lst, chunk->hold_1);
	else if (chunk->is_2_holded && !chunk->is_1_holded)
		rotate_one_hold(lst, chunk->hold_2);
	if (chunk->is_1_holded || chunk->is_2_holded)
	{
		check_push_b(lst);
		i = 0;
	}
	return (i);
}
