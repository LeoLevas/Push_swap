/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:08:17 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/27 19:01:14 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	can_next_lowest(int *lst, int len, int lowest, int *new_lowest);

void	simple_lst(t_int_list *lst, t_int_list *lst_simple)
{
	int	i;
	int	lowest;
	int	next_lowest;
	int	highest;
	int	pos;
	int	*lst_a;

	lst_a = lst->lst_a;
	lowest = get_lowest_elem(lst_a, lst->max_len);
	next_lowest = lowest;
	highest = get_highest_elem(lst_a, lst->max_len);
	ft_printf("Lowest : %d | highest : %d\n", lowest, highest);
	i = 0;
	pos = get_int_pos_in_list(lst_a, lst->max_len, lowest++);
	ft_printf("Starting while loop\n");
	while (lowest <= highest && can_next_lowest(lst_a, lst->max_len, lowest, &next_lowest))
	{
		lowest = next_lowest;
		pos = get_int_pos_in_list(lst_a, lst->max_len, lowest++);
		*(lst_simple->lst_a + pos) = i++;
	}
}

int	can_next_lowest(int *lst, int len, int lowest, int *new_lowest)
{
	int	i;
	int	temp_set;

	i = 0;
	temp_set = 0;
	while (lst[i] && i < len && temp_set == 0)
	{
		if (lst[i] > lowest)
		{
			temp_set = 1;
			*new_lowest = lst[i];
			break ;
		}
		i++;
	}
	if (!temp_set)
		return (0);
	while (lst[i] && i < len)
	{
		if (lst[i] > lowest && lst[i] < *new_lowest)
			*new_lowest = lst[i];
		i++;
	}
	return (1);
}

int	get_int_pos_in_list(int *lst, int len, int nbr)
{
	int	i;

	i = 0;
	while (*(lst + i) != nbr && i < len)
		i++;
	if (*(lst + i) == nbr)
	{
		ft_printf("find pos for %d\n", nbr);
		return (i);
	}
	return (-1);
}
