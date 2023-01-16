/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:37:04 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/16 11:37:22 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
