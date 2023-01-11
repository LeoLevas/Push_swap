/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:10:31 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/11 16:39:51 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	less_three_sort(struct s_int_list *lst)
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

void	less_five_sort(struct s_int_list *lst)
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
