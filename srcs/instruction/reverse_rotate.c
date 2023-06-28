/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:49:26 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/28 23:33:25 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *lst, int len)
{
	int	i;
	int	temp1;
	int	temp2;

	i = 1;
	if (len < 2)
		return ;
	temp1 = lst[0];
	while (i < len - 1)
	{
		temp2 = lst[i];
		lst[i] = temp1;
		temp1 = temp2;
		i++;
	}
	temp2 = lst[i];
	lst[i] = temp1;
	lst[0] = temp2;
}
