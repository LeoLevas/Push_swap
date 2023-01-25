/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:50:17 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/25 16:04:32 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_int_list	*lst;

	lst = init_list(argc, argv);
	if (!lst)
		return (ft_printf("Error\n"));
	print_list(lst, 2);
	if (is_stack_sorted(lst))
		return (kill_lst(lst));
	if (lst->len_a <= 3 && !is_stack_sorted(lst))
		less_three_sort(lst);
	if (lst->len_a <= 5 && !is_stack_sorted(lst))
		less_five_sort(lst);
	else
		big_sort(lst);
	ft_printf("-----AFTER  SORT-----\n");
	print_list(lst, 1);
	if (is_stack_sorted(lst))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (kill_lst(lst));
}
