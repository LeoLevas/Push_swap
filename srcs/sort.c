/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:10:31 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/25 16:41:01 by llevasse         ###   ########.fr       */
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
			while (get_elem_position_in_sort(lst, *lst->lst_b) != 0)
				ft_ra(lst);
		}
		if (pos > (lst->len_a / 2))
		{
			while (get_elem_position_in_sort(lst, *lst->lst_b) != 0)
				ft_rra(lst);
		}
		ft_pa(lst);
		if (*lst->lst_a > *(lst->lst_a + 1))
			ft_ra(lst);
	}
	return ;
}

void	big_sort(t_int_list *lst)
{
	int		i;

	i = 0;
	while (!is_stack_sorted(lst) && i < 1)
	{
		while (get_int_pos_in_list(lst, get_lsd(lst->lst_a, lst->len_a, i)) != -1)
		{
			rotate_one_hold(lst, get_lsd(lst->lst_a, lst->len_a, i));
			check_push_b(lst);
			print_list(lst, 1);
		}
		i++;
	}
	return ;
	while (lst->len_a != lst->max_len)
	{
		get_highest_to_top(lst);
		ft_pa(lst);
	}
}

void	check_push_b(t_int_list *lst)
{
	get_highest_to_top(lst);
	rotate_best_pos(lst);
	if (get_highest_elem(lst->lst_b, lst->len_b) < *lst->lst_b)
		ft_rb(lst);
	ft_pb(lst);
	print_list(lst, 1);
	get_highest_to_top(lst);
}
