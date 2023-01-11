/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:50:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/11 15:49:33 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(int *lst_1, int *lst_2, int *len_1, int *len_2)
{
	int	i;
	int	temp;

	if (!*lst_2)
		return ;
	i = 0;
	temp = *lst_2 ;
	while (i < *len_2)
	{
		i++;
		lst_2++;
		*(lst_2 - 1) = *lst_2;
	}
	lst_2 -= 1;
	*lst_2 = 0;
	*len_2 -= 1;
	if (*len_1 == 0)
	{
		*lst_1 = temp;
		*len_1 += 1;
	}
	else
	{
		i = 1;
		while (i < *len_1)
		{
			i++;
			lst_1++;
		}
		lst_1++;
		while (i > 0)
		{
			*lst_1 = *(lst_1 - 1);
			lst_1--;
			i--;
		}
		*lst_1 = temp;
		*len_1 += 1;
	}
}
