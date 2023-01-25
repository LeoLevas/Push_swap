/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_best_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:27:02 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/25 17:05:03 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_best_pos(t_int_list *lst)
{
	int	biggest_in_b;
	int	smallest_in_b;

	if (lst->len_b == 0)
		return ;
	biggest_in_b = get_highest_elem(lst->lst_b, lst->len_b);
	smallest_in_b = get_lowest_elem(lst->lst_b, lst->len_b);
	if (*lst->lst_a > biggest_in_b)
		return ;
	if (*lst->lst_a < smallest_in_b)
		return ;
	return (rotate_one_hold_b(lst, *lst->lst_a));
}

/* void	new_smallest(t_int_list *lst)
{
	int	pos;

	pos = get_lowest_elem_pos(lst->lst_b, lst->len_b);
	if (!pos)
		return ;
	if (pos < (lst->len_b / 2))
	{
		while (get_lowest_elem_pos(lst->lst_b, lst->len_b) != 0)
			ft_rb(lst);
	}
	else
	{
		while (get_lowest_elem_pos(lst->lst_b, lst->len_b) != 0)
			ft_rrb(lst);
	}
}

void	new_highest(t_int_list *lst)
{
	int	pos;

	pos = get_best_pos_in_b(lst);
	if (!pos)
		return ;
	if (pos < (lst->len_b / 2))
	{
		while (pos != 0)
		{
			ft_rb(lst);
			pos = get_best_pos_in_b(lst);
		}
	}
	else
	{
		while (pos != 0)
		{
			if (*lst->lst_a == 13)
				print_list(lst, 1);
			ft_rrb(lst);
			pos = get_best_pos_in_b(lst);
		}
	}
}
 */

void	get_highest_to_top(t_int_list *lst)
{
	int	pos;

	pos = get_highest_elem_pos(lst->lst_b, lst->len_b);
	if (!pos)
		return ;
	if (pos < (lst->len_b / 2))
	{
		while (pos != 0)
		{
			ft_rb(lst);
			pos = get_highest_elem_pos(lst->lst_b, lst->len_b);
		}
	}
	else
	{
		while (pos != 0)
		{
			ft_rrb(lst);
			pos = get_highest_elem_pos(lst->lst_b, lst->len_b);
		}
	}
}
