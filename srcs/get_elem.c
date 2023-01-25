/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:45:36 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/25 23:06:25 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	get_highest_elem(int *lst, int len)
{
	int	i;
	int	temp;

	i = 0;
	temp = *lst;
	while (i < len)
	{
		if (*lst > temp)
			temp = *lst;
		lst++;
		i++;
	}
	return (temp);
}

int	get_lowest_elem(int *lst, int len)
{
	int	i;
	int	temp;

	i = 0;
	temp = *lst;
	while (i < len)
	{
		if (*lst < temp)
			temp = *lst;
		lst++;
		i++;
	}
	return (temp);
}

int	get_elem_position_in_sort(t_int_list *lst, int temp)
{
	int	i;
	int	*lst_a;

	i = 0;
	lst_a = lst->lst_a;
	if (temp < *lst_a)
		return (i);
	else if (temp > *lst_a && temp > *(lst_a + lst->len_a))
		return (i);
	while (i < lst->len_a)
	{
		if (*lst_a < temp && *(lst_a + 1) > temp)
			break ;
		lst_a++;
		i++;
	}
	return (i);
}
