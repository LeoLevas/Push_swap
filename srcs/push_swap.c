/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:50:17 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/14 18:48:56 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_int_list	*lst;

	if (argc == 1)
		return (0);

	lst = init_list(argc, argv);
	if (!lst)
		return (ft_printf("Error\n"));

/* 	ft_printf("-----BEFORE SORT-----\n");
 */
/* 	print_list(lst);
 */
	if (is_stack_sorted(lst))
		return (kill_lst(lst));

	if (lst->len_a <= 3 && !is_stack_sorted(lst))
		less_three_sort(lst);

	if (lst->len_a <= 5 && !is_stack_sorted(lst))
		less_five_sort(lst);
	else
		big_sort(lst);
	ft_printf("-----AFTER  SORT-----\n");

 	
 	print_list(lst, 0);
	
/* 	ft_printf("lowest : %i || highest : %i\n", get_lowest_elem_pos(lst->lst_a, lst->len_a), get_highest_elem_pos(lst->lst_a, lst->len_a));
	ft_printf("lowest : %i || highest : %i\n", get_lowest_elem(lst->lst_a, lst->len_a), get_highest_elem(lst->lst_a, lst->len_a));
 */	
	return (kill_lst(lst));
}

