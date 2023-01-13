/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:30:03 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/12 23:51:14 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_stack_sorted(t_int_list *lst)
{
	int	i;
	int	*lst_a;

	lst_a = lst->lst_a;
	i = 1;
	lst_a++;
	while (*lst_a >= *(lst_a - 1) && i < lst->len_a)
	{
		lst_a++;
		i++;
	}
	if ((*lst_a && *lst_a < *(lst_a - 1)) || \
	(!*lst_a && *(lst_a - 1) < *(lst_a - 2)))
		return (0);
	return (1);
}

int	is_duplicate(int *lst)
{
	int	i;
	int	j;

	i = 0;
	while (lst[i])
	{
		j = 0;
		while (j < i)
		{
			if (lst[j] == lst[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


void	set_zero(int *lst, int len)
{
	int	i;

	i = 0;

	while (i <= len)
	{
		*lst++ = 0;
		i++;
	}
}

int	*get_list(int argc, char *argv[])
{
	int	*lst;
	int	i;

	lst = malloc((argc + 1) * sizeof(int));
	if (!lst)
		return (NULL);
	set_zero(lst, argc);
	i = 0;
	while (i++ < argc && argv[i] && is_char_only_digits(argv[i]))
		*lst++ = ft_atoi(argv[i]);
	lst -= (i - 1);
	if (!is_char_only_digits(argv[i]))
		return (free(lst), NULL);
	return (lst);
}

int	is_char_only_digits(char *str)
{
	int	was_digit;

	if (!str)
		return (1);
	was_digit = 0;

	while (ft_isdigit(*str) || *str == ' ' || *str == '-' || *str == '+')
	{
		if (ft_isdigit(*str))
			was_digit = 1;
		str++;
	}
	if (ft_isalpha(*str))
		return (0);
	if (was_digit)
		return (1);
	return (0);
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
	ft_printf("lst A\t\tlst B\n");
	while (i < len_a || i < lst->len_b)
	{
		if (i < len_a)
			ft_printf("%i", *lst_a++);
		ft_printf("\t\t");
		if (i < len_b)
			ft_printf("%i", *lst_b++);
		ft_printf("\n");
		i++;
	}
}

int	get_elem_position_in_sort(t_int_list *lst, int temp)
{
	int	i;
	int	*lst_a;

	i = 0;
	lst_a = lst->lst_a;
	if (temp < *lst_a)
		return (i);
	else if (temp > *lst_a && temp > *(lst_a + lst->len_a))
		return (i);
	while (i < lst->len_a)
	{
		if (*lst_a < temp && *(lst_a + 1) > temp)
			break ;
		lst_a++;
		i++;
	}

	return (i);
}

/* int	main(int argc, char *argv[])
{
	t_int_list	*lst;

	if (argc == 1)
		return (0);

	lst = init_list(argc, argv);
	if (!lst)
		return (0);
	print_list(lst);
	ft_printf("lstA is sorted : %i\n\n\n", is_sorted(lst));
	ft_printf("lstA swap\n");
	ft_sa(lst);
	print_list(lst);
	ft_printf("lstB swap\n");
	ft_sb(lst);

	ft_printf("push 1 times to B\n");
	ft_pb(lst);
	print_list(lst);
	ft_printf("push 1 times to B\n");
	ft_pb(lst);
	print_list(lst);
	ft_printf("push 1 times to B\n");
	ft_pb(lst);
	print_list(lst);
	ft_printf("push 1 times to B\n");
	ft_pb(lst);
	print_list(lst);
	ft_printf("push 1 times to B\n");
	ft_pb(lst);
	print_list(lst);
	ft_printf("push 1 times to A\n");
	ft_pa(lst);
	print_list(lst);


	ft_printf("rotate\n");
	ft_rr(lst);
	print_list(lst);
	ft_printf("reverse rotate\n");
	ft_rrr(lst);
	print_list(lst);

	free(lst->lst_a);
	free(lst->lst_b);
	free(lst);
} */