/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:30:03 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/10 13:50:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_len_list(int *lst)
{
	int	i;

	i = 0;
	while (*lst != 0)
	{
		lst++;
		i++;
	}
	return (i);
}

static int	is_sorted(int *lst)
{
	int	i;

	i = 1;
	while (lst[i] >= lst[i - 1] && lst[i])
		i++;
	if ((lst[i] && lst[i] < lst[i - 1]) || (!lst[i] && lst[i - 1] < lst[i - 2]))
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

static void	swap(int *lst)
{
	int	temp;

	if (!lst[0] || !lst[1])
		return ;
	temp = lst[0];
	lst[0] = lst[1];
	lst[1] = temp;
}

static void	push(int *lst_1, int *lst_2)
{
	int	i;
	int	temp;

	if (!lst_2[0])
		return ;
	i = get_len_list(lst_2);
	while (*lst_2 != 0)
		lst_2++;
	lst_2--;
	temp = *lst_2 ;
	*lst_2 = 0;
	if (lst_1[0] == '\0')
	{
		lst_1[0] = temp;
		lst_1[1] = 0;
	}
	else
	{
		i = 0;
		while (lst_1[i])
			i++;
		if (lst_1[i] == '\0')
		{
			while (i > 0)
			{
				lst_1[i] = lst_1[i - 1];
				i--;
			}
			lst_1[i] = temp;
		}
	}
}

//décale d'une position vers le haut
static void	rotate(int *lst)
{
	int	i;
	int	len;
	int	temp1;
	int	temp2;

	len = 0;
	i = 1;
	if (!lst[0])
		return ;
	while (lst[len])
		len++;
	temp1 = lst[0];
	while (i < len - 1)
	{
		temp2 = lst[i];
		lst[i] = temp1;
		temp1 = temp2;
		i++;
	}
	temp2 = lst[i];
	lst[i] = temp1;
	lst[0] = temp2;
}

static void	reverse_rotate(int *lst)
{
	int	len;
	int	temp1;
	int	temp2;
	int	second;

	len = get_len_list(lst) - 1;
	if (!lst[0])
		return ;
	temp1 = lst[0];
	second = lst[1];
	while (len > 0)
	{
		temp2 = lst[len];
		lst[len] = temp1;
		temp1 = temp2;
		len--;
	}
	temp2 = lst[len];
	lst[len] = temp1;
	lst[0] = second;
}

static void	print_list(int *lstA, int *lstB, int len)
{
	int	i;

	i = 0;
	ft_printf("lst A\t\tlst B\n");
	while (i < len)
	{
		if (*lstA)
			ft_printf("%i", *lstA++);
		ft_printf("\t\t");
		if (*lstB)
			ft_printf("%i", *lstB++);
		ft_printf("\n");
		i++;
		if (!*lstA && !*lstB)
			break ;
	}
}

#include <stdio.h>

static void set_zero(int *lst, int len)
{
	int	i;

	i = 0;

	while (i <= len)
	{
		*lst++ = 0;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	*lst_a;
	int	*lst_b;
	int	i;

	lst_a = malloc((argc + 1) * sizeof(int));
	if (!lst_a)
		return (1);
	lst_b = malloc((argc + 1) * sizeof(int));
	if (!lst_b)
		return (free(lst_a), 1);
	set_zero(lst_a, argc);
	set_zero(lst_b, argc);
	i = 0;
	while (i++ < argc && argv[i])
		*lst_a++ = ft_atoi(argv[i]);
	lst_a -= (i - 1);
	print_list(lst_a, lst_b, argc - 1);
	printf("lstA is sorted : %i\n\n\n", is_sorted(lst_a));
	ft_printf("lstA swap\n");
	swap(lst_a);
	print_list(lst_a, lst_b, argc - 1);
	ft_printf("lstB swap\n");
	swap(lst_b);
	print_list(lst_a, lst_b, argc - 1);
	ft_printf("push 2 times to B\n");
	push(lst_b, lst_a);
	push(lst_b, lst_a);
	print_list(lst_a, lst_b, argc - 1);
	ft_printf("rotate\n");
	rotate(lst_a);
	rotate(lst_b);
	print_list(lst_a, lst_b, argc - 1);
	ft_printf("reverse rotate\n");
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	print_list(lst_a, lst_b, argc - 1);
	free(lst_a);
	free(lst_b);
}