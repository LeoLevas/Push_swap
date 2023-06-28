/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:50:17 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/28 08:38:49 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	ft_printf("\33[2K\rlst A\t\tlst B\n");
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

int	main(int argc, char *argv[])
{
	t_int_list	*lst;
	t_int_list	*lst_simple;

	if (argc == 1)
		return (0);
	lst = init_list(argc, argv);
	lst_simple = NULL;
	if (!lst)
		return (kill_lst(lst, lst_simple), ft_printf("Error\n"));
	if (lst->len_a > 5)
	{
		lst_simple = init_list(argc, argv);
		if (!lst_simple)
			return (kill_lst(lst, lst_simple), ft_printf("Error\n"));
		simple_lst(lst, lst_simple);
		big_sort(lst, lst_simple);
	}
	if (is_stack_sorted(lst))
		return (kill_lst(lst, lst_simple), 0);
	if (lst->len_a <= 5 && !is_stack_sorted(lst))
		less_five_sort(lst);
	//print_list(lst);
	return (kill_lst(lst, lst_simple), 0);
}
