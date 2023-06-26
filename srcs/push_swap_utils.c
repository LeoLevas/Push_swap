/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:30:03 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/26 11:11:12 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_stack_sorted(t_int_list *lst)
{
	int	i;
	int	*lst_a;

	if (lst->len_a == 0)
		return (1);
	lst_a = lst->lst_a;
	i = 1;
	lst_a++;
	while (*lst_a >= *(lst_a - 1) && i < lst->len_a - 1)
	{
		lst_a++;
		i++;
	}
	if ((*lst_a < *(lst_a - 1)))
		return (0);
	return (1);
}

int	is_duplicate(int *lst, int len)
{
	int	i;
	int	j;

	i = 0;
	while (lst[i] && i < len)
	{
		j = 0;
		while (j < i)
		{
			if (lst[j] == lst[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	set_zero(int *lst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*lst++ = 0;
		i++;
	}
}

int	is_char_only_digits(char *str)
{
	int	was_digit;

	if (!str)
		return (1);
	was_digit = 0;
	while (ft_isdigit(*str) || *str == ' ' || *str == '-' || *str == '+')
	{
		if (ft_isdigit(*str))
			was_digit = 1;
		str++;
	}
	if (ft_isalpha(*str))
		return (0);
	if (was_digit)
		return (1);
	return (0);
}

int	get_range(int min, int max)
{
	int	temp;

	if (min > max)
	{
		temp = max;
		max = min;
		min = temp;
	}
	if (min >= 0 && max > 0)
		return (max - min);
	if (min <= 0)
		return (max + (min * -1));
	return (0);
}
