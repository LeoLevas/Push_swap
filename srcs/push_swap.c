/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:50:17 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/11 16:10:28 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	struct s_int_list	*lst;

	if (argc == 1)
		return (0);

	lst = init_list(argc, argv);
	if (!lst)
		return (ft_printf("Error\n"));

	ft_printf("-----BEFORE SORT-----\n");

	print_list(lst);

	if (is_stack_sorted(lst))
		return (kill_lst(lst));

	if (lst->len_a <= 3 && !is_stack_sorted(lst))
		less_three_sort(lst);

	if (lst->len_a <= 5 && !is_stack_sorted(lst))
		less_five_sort(lst);
	ft_printf("-----AFTER  SORT-----\n");

	print_list(lst);
	return (kill_lst(lst));
}

