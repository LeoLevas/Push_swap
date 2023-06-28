/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 08:33:26 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/28 08:41:08 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_inst(t_int_list *lst)
{
	ft_printf("\33[2K\rpa : %d | pb : %d | ra : %d | rb : %d | rr : %d \
| rra : %d | rrb : %d | rrr : %d | sa : %d | sb : %d | ss : %d",
		lst->pa, lst->pb, lst->ra, lst->rb, lst->rr, lst->rra, lst->rrb,
		lst->rrr, lst->sa, lst->sb, lst->ss);
	usleep(20);
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
