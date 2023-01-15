/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:10:31 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/15 11:07:23 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	less_three_sort(t_int_list *lst)
{
	if (lst->len_a == 1)
		return ;
	if (lst->len_a == 2 && *lst->lst_a > *(lst->lst_a + 1))
		return (ft_sa(lst));
	if (lst->len_b == 2 && *lst->lst_b > *(lst->lst_b + 1))
		(ft_sb(lst));
	if (*lst->lst_a > *(lst->lst_a + 1) && *lst->lst_a < *(lst->lst_a + 2) \
		&& *(lst->lst_a + 1) < *(lst->lst_a + 2))
		return (ft_sa(lst));
	if (*lst->lst_a > *(lst->lst_a + 1) && *lst->lst_a > *(lst->lst_a + 2) \
		&& *(lst->lst_a + 1) > *(lst->lst_a + 2))
		return (ft_sa(lst), ft_rra(lst));
	if (*lst->lst_a > *(lst->lst_a + 1) && *lst->lst_a > *(lst->lst_a + 2) \
		&& *(lst->lst_a + 1) < *(lst->lst_a + 2))
		return (ft_ra(lst));
	if (*lst->lst_a < *(lst->lst_a + 1) && *lst->lst_a < *(lst->lst_a + 2) \
		&& *(lst->lst_a + 1) > *(lst->lst_a + 2))
		return (ft_sa(lst), ft_ra(lst));
	if (*lst->lst_a < *(lst->lst_a + 1) && *lst->lst_a > *(lst->lst_a + 2) \
		&& *(lst->lst_a + 1) > *(lst->lst_a + 2))
		return (ft_rra(lst));
	return ;
}

void	less_five_sort(t_int_list *lst)
{
	int	pos;

	while (lst->len_a > 3)
		ft_pb(lst);
	less_three_sort(lst);
	while (lst->len_b > 0)
	{
		pos = get_elem_position_in_sort(lst, *lst->lst_b);
		if (pos <= (lst->len_a / 2))
		{
			while (pos != 0)
			{
				ft_ra(lst);
				pos = get_elem_position_in_sort(lst, *lst->lst_b);
			}
		}
		if (pos > (lst->len_a / 2))
		{
			while (pos != 0)
			{
				ft_rra(lst);
				pos = get_elem_position_in_sort(lst, *lst->lst_b);
			}
		}
		ft_pa(lst);
	}
	if (*lst->lst_a > *(lst->lst_a + 1))
		ft_ra(lst);
	return ;
}

void	big_sort(t_int_list *lst)
{
	int		i;
	int		is_1_holded;
	int		is_2_holded;
	t_chunk	*chunk;

	chunk = init_chunk(lst);
	if (!chunk)
		return ;
	while (!is_stack_sorted(lst) && chunk->index < nbr_chunk(lst))
	{
		i = 0;
		while (i < lst->len_a && need_search_chunk(lst, chunk) && lst->len_a)
		{
			if (is_in_chunk(lst, chunk, *(lst->lst_a + i)))
			{
				chunk->hold_1 = *(lst->lst_a + i);
				is_1_holded = 1;
			}
			if (is_in_chunk(lst, chunk, *(lst->lst_a + ((lst->len_a) - i))))
			{
				chunk->hold_2 = *(lst->lst_a + (lst->len_a - i));
				is_2_holded = 1;
			}
			i++;
			if (is_1_holded && is_2_holded)
				rotate_holds(lst, chunk->hold_1, chunk->hold_2);
			else if (is_1_holded && !is_2_holded)
				rotate_one_hold(lst, chunk->hold_1);
			else if (is_2_holded && !is_1_holded)
				rotate_one_hold(lst, chunk->hold_2);
			if ((chunk->hold_1 > 0 && is_1_holded) || (chunk->hold_2 > 0 && is_2_holded))
				ft_printf("");
			if (is_1_holded || is_2_holded)
			{
				check_push_b(lst);
				i = 0;
			}
			is_1_holded = 0;
			is_2_holded = 0;
			if (*lst->lst_b >= -12 && i == 2)
				print_list(lst, 0);
		}
		chunk->index++;
		chunk->min += chunk->length;
	}
	print_list(lst, 1);
	while (lst->len_a != lst->max_len)
	{
		get_highest_to_top(lst);
		ft_pa(lst);
	}
}

void	check_push_b(t_int_list *lst)
{
	if (lst->len_b < 2)
		return (ft_pb(lst));
	rotate_best_pos(lst);
	return (ft_pb(lst));
}
