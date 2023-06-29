/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:50:17 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/29 16:24:29 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(t_int_list **lst, t_int_list **lst_simple, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_int_list	*lst;
	t_int_list	*lst_simple;

	lst = NULL;
	lst_simple = NULL;
	if (parse(&lst, &lst_simple, argc, argv) == 1)
		return (1);
	if (lst->len_a > 5)
		big_sort(lst, lst_simple);
	if (lst->max_len <= 5 && !is_stack_sorted(lst))
		less_five_sort(lst);
	if (!CAN_PRINT)
		print_list(lst);
	return (kill_lst(lst, lst_simple), 0);
}

int	parse(t_int_list **lst, t_int_list **lst_simple, int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	*lst = init_list(argc, argv);
	if (!*lst)
		return (ft_putendl_fd("Error", 2), 1);
	if ((*lst)->len_a == 1 || is_stack_sorted(*lst))
	{
		kill_lst(*lst, *lst_simple);
		exit(0);
	}
	if ((*lst)->len_a > 5)
	{
		//*lst_simple = init_list(argc, argv);
		if (!*lst_simple)
		{
			kill_lst(*lst, *lst_simple);
			return (ft_putendl_fd("Error", 2), 1);
		}
		simple_lst(*lst, *lst_simple);
	}
	return (0);
}
