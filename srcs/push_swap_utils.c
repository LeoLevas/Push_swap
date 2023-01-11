/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:30:03 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/11 11:59:10 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(int *lst, int len)
{
	int	i;

	i = 1;
	lst++;
	while (*lst >= *(lst - 1) && i < len)
	{
		lst++;
		i++;
	}
	if ((*lst && *lst < *(lst - 1)) || (!*lst && *(lst - 1) < *(lst - 2)))
		return (0);
	return (1);
}

/* static int	is_duplicate(int *lst)
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
 */

void	print_list(int *lstA, int *lstB, int len_a, int len_b)
{
	int	i;

	i = 0;
	ft_printf("lst A\t\tlst B\n");
	while (i < len_a || i < len_b)
	{
		if (i < len_a)
			ft_printf("%i", *lstA++);
		ft_printf("\t\t");
		if (i < len_b)
			ft_printf("%i", *lstB++);
		ft_printf("\n");
		i++;
	}
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

int	main(int argc, char *argv[])
{
	struct s_int_list	*lst;

	if (argc == 1)
		return (0);

	lst = init_list(argc, argv);
	if (!lst)
		return (0);
	print_list(lst->lst_a, lst->lst_b, *lst->ptr_a, *lst->ptr_b);
	ft_printf("lstA is sorted : %i\n\n\n", is_sorted(lst->lst_a, *lst->ptr_a));
	ft_printf("lstA swap\n");
	swap(lst->lst_a);
	print_list(lst->lst_a, lst->lst_b, *lst->ptr_a, *lst->ptr_b);
	ft_printf("lstB swap\n");
	swap(lst->lst_b);

	ft_printf("push 1 times to B\n");
	push(lst->lst_b, lst->lst_a, lst->ptr_b, lst->ptr_a);
	print_list(lst->lst_a, lst->lst_b, *lst->ptr_a, *lst->ptr_b);
	ft_printf("push 1 times to B\n");
	push(lst->lst_b, lst->lst_a, lst->ptr_b, lst->ptr_a);
	print_list(lst->lst_a, lst->lst_b, *lst->ptr_a, *lst->ptr_b);
	ft_printf("push 1 times to B\n");
	push(lst->lst_b, lst->lst_a, lst->ptr_b, lst->ptr_a);
	print_list(lst->lst_a, lst->lst_b, *lst->ptr_a, *lst->ptr_b);
	ft_printf("push 1 times to B\n");
	push(lst->lst_b, lst->lst_a, lst->ptr_b, lst->ptr_a);
	print_list(lst->lst_a, lst->lst_b, *lst->ptr_a, *lst->ptr_b);
	ft_printf("push 1 times to B\n");
	push(lst->lst_b, lst->lst_a, lst->ptr_b, lst->ptr_a);
	print_list(lst->lst_a, lst->lst_b, *lst->ptr_a, *lst->ptr_b);
	ft_printf("push 1 times to A\n");
	push(lst->lst_a, lst->lst_b, lst->ptr_a, lst->ptr_b);
	print_list(lst->lst_a, lst->lst_b, *lst->ptr_a, *lst->ptr_b);


	ft_printf("rotate\n");
	rotate(lst->lst_a, *lst->ptr_a);
	rotate(lst->lst_b, *lst->ptr_b);
	print_list(lst->lst_a, lst->lst_b, *lst->ptr_a, *lst->ptr_b);
	ft_printf("reverse rotate\n");
	reverse_rotate(lst->lst_a, lst->ptr_a);
	reverse_rotate(lst->lst_b, lst->ptr_b);
	print_list(lst->lst_a, lst->lst_b, *lst->ptr_a, *lst->ptr_b);

	free(lst->lst_a);
	free(lst->lst_b);
	free(lst);
}