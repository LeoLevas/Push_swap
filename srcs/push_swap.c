/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:50:17 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/26 15:34:25 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_int_list	*lst;
	t_int_list	*lst_simple;

	if (argc == 1)
		return (0);
	lst = init_list(argc, argv);
	lst_simple = init_list(argc, argv);
	if (!lst || !lst_simple)
		return (kill_lst(lst, lst_simple), ft_printf("Error\n"));
	simple_lst(lst, lst_simple);
	if (is_stack_sorted(lst))
		return (kill_lst(lst, lst_simple), 0);
	if (lst->len_a <= 3 && !is_stack_sorted(lst))
		less_three_sort(lst);
	if (lst->len_a <= 5 && !is_stack_sorted(lst))
		less_five_sort(lst);
	else if (lst->max_len > 5)
		big_sort(lst, lst_simple);
	return (kill_lst(lst, lst_simple), 0);
}
