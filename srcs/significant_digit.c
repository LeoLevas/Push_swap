/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   significant_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:01:21 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/20 16:26:19 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_lsd(int *lst, int len, int digit)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (*(lst + i) % 10 == digit)
			return (*(lst + i));
		if (*(lst + i) == digit)
			return (*(lst + i));
		i++;
	}
	return (0);
}

int	get_msd(int	*lst, int len, int digit)
{
	int	i;
	int	temp;

	i = 0;
	while (i < len)
	{
		temp = *(lst + i);
		while (get_int_len(temp) > 1)
			temp /= 10;
		if (temp == digit)
			return (*(lst + i));
		i++;
	}
	return (0);
}
