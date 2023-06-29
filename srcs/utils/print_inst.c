/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:33:26 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/29 09:43:32 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_inst(t_int_list *lst)
{
	ft_printf("\33[2K\rpa : %d | pb : %d | ra : %d | rb : %d | rr : %d \
| rra : %d | rrb : %d | rrr : %d | sa : %d | sb : %d | ss : %d",
		lst->pa, lst->pb, lst->ra, lst->rb, lst->rr, lst->rra, lst->rrb,
		lst->rrr, lst->sa, lst->sb, lst->ss);
}

void	init_inst_count(t_int_list *lst)
{
	lst->pa = 0;
	lst->pb = 0;
	lst->ra = 0;
	lst->rb = 0;
	lst->rr = 0;
	lst->rra = 0;
	lst->rrb = 0;
	lst->rrr = 0;
	lst->sa = 0;
	lst->sb = 0;
	lst->ss = 0;
}

void	print_list(t_int_list *lst)
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
	ft_printf("\nlst A\t\tlst B\n");
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
