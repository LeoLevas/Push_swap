/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:24:23 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/14 18:45:31 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_int_pos_in_list_b(t_int_list *lst, int nbr)
{
	int	i;

	i = 0;
	while (*(lst->lst_b + i) != nbr)
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
	if (nbr == *lst->lst_b)
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

void	rotate_best_pos(t_int_list *lst)
{
	int	pos;
	int	biggest_in_b;

	biggest_in_b = get_highest_elem(lst->lst_b, lst->len_b);
	if (*lst->lst_a < biggest_in_b)
	{
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
				ft_rrb(lst);
				pos = get_best_pos_in_b(lst);
			}
		}
	}
	else
	{
		pos = get_lowest_elem_pos(lst->lst_b, lst->len_b);
		if (!pos)
			return ;
		if (pos < (lst->len_b / 2))
		{
			while (pos != 0)
			{
				ft_rb(lst);
				pos = get_lowest_elem_pos(lst->lst_b, lst->len_b);
			}
		}
		else
		{
			while (pos != 0)
			{
				ft_rrb(lst);
				pos = get_lowest_elem_pos(lst->lst_b, lst->len_b);
			}
		}
	}
}

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
