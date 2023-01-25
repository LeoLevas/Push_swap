/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_not_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:44:01 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/25 22:28:21 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_int_list *lst, int all)
{
	int	i;
	int	*lst_a;
	int	*lst_b;
	int	len_a;
	int	len_b;

	lst_a = lst->lst_a;
	lst_b = lst->lst_b;
	len_a = lst->len_a;
	len_b = lst->len_b;
	i = 0;
	if (all == 0)
	{
		ft_printf("lst A\t\tlst B\n");
		while (i < len_a || i < lst->len_b)
		{
			if (i < len_a)
				ft_printf("%i : %i", i, *lst_a++);
			ft_printf("\t\t\t");
			if (i < len_b)
				ft_printf("%i", *lst_b++);
			ft_printf("\n");
			i++;
		}
	}
	if (all == 1)
	{
		ft_printf("lst B\n");
		while (i < lst->len_b)
		{
			if (i < len_b)
				ft_printf("%i : %i", i, *lst_b++);
			ft_printf("\n");
			i++;
		}	
	}
	if (all == 2)
	{
		ft_printf("lst A\t\tlst B\n");
		while (i <= lst->max_len)
		{
			ft_printf("%i : %i", i, *lst_a++);
			ft_printf("\t\t\t");
			ft_printf("%i", *lst_b++);
			ft_printf("\n");
			i++;
		}
	}
}
