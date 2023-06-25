/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:10:31 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/25 21:10:56 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	less_three_sort(t_int_list *lst)
{
	if (lst->len_a == 1)
		return ;
	if (lst->len_a == 2 && *lst->lst_a > *(lst->lst_a + 1))
		return (ft_sa(lst, NULL));
	if (lst->len_b == 2 && *lst->lst_b > *(lst->lst_b + 1))
		(ft_sb(lst, NULL));
	if (*lst->lst_a > *(lst->lst_a + 1) && *lst->lst_a < *(lst->lst_a + 2) \
		&& *(lst->lst_a + 1) < *(lst->lst_a + 2))
		return (ft_sa(lst, NULL));
	if (*lst->lst_a > *(lst->lst_a + 1) && *lst->lst_a > *(lst->lst_a + 2) \
		&& *(lst->lst_a + 1) > *(lst->lst_a + 2))
		return (ft_sa(lst, NULL), ft_rra(lst, NULL));
	if (*lst->lst_a > *(lst->lst_a + 1) && *lst->lst_a > *(lst->lst_a + 2) \
		&& *(lst->lst_a + 1) < *(lst->lst_a + 2))
		return (ft_ra(lst, NULL));
	if (*lst->lst_a < *(lst->lst_a + 1) && *lst->lst_a < *(lst->lst_a + 2) \
		&& *(lst->lst_a + 1) > *(lst->lst_a + 2))
		return (ft_sa(lst, NULL), ft_ra(lst, NULL));
	if (*lst->lst_a < *(lst->lst_a + 1) && *lst->lst_a > *(lst->lst_a + 2) \
		&& *(lst->lst_a + 1) > *(lst->lst_a + 2))
		return (ft_rra(lst, NULL));
	return ;
}

void	less_five_sort(t_int_list *lst)
{
	int	pos;

	while (lst->len_a > 3)
		ft_pb(lst, NULL);
	less_three_sort(lst);
	while (lst->len_b > 0)
	{
		pos = get_elem_position_in_sort(lst, *lst->lst_b);
		if (pos <= (lst->len_a / 2))
		{
			while (get_elem_position_in_sort(lst, *lst->lst_b) != 0)
				ft_ra(lst, NULL);
		}
		if (pos > (lst->len_a / 2))
		{
			while (get_elem_position_in_sort(lst, *lst->lst_b) != 0)
				ft_rra(lst, NULL);
		}
		ft_pa(lst, NULL);
		if (*lst->lst_a > *(lst->lst_a + 1))
			ft_ra(lst, NULL);
	}
	return ;
}

void	big_sort(t_int_list *lst, t_int_list *lst_simple)
{
	int		i;
	int		j;

	i = 0;
	while (!is_stack_sorted(lst_simple))
	{
		j = 0;
		while (j < lst->max_len)
		{
			if (((*lst_simple->lst_a >> i) & 1) == 1)
				ft_ra(lst, lst_simple);
			else
				ft_pb(lst, lst_simple);
			j++;
		}
		i++;
		while (lst->len_b != 0)
			ft_pa(lst, lst_simple);
	}
}
