/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:15:20 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/28 13:29:21 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_int_list	*init_list(int argc, char *argv[])
{
	t_int_list	*lst;

	lst = malloc(sizeof(t_int_list));
	if (!lst)
		return (NULL);
	lst->lst_a = get_list(lst, &argc, argv);
	if (!lst->lst_a)
		return (free(lst), NULL);
	lst->lst_b = malloc(argc * sizeof(int));
	if (!lst->lst_b)
	{
		free(lst->lst_a);
		return (free(lst), NULL);
	}
	set_zero(lst->lst_b, argc - 1);
	lst->len_b = 0;
	init_inst_count(lst);
	return (lst);
}

int	*get_list(t_int_list *lst, int *argc, char *argv[])
{
	int	*lst_a;
	int	i;

	if (*argc == 2)
		return (get_list_split(lst, argc, ft_split(argv[1], " ")));
	lst_a = malloc((*argc) * sizeof(int));
	if (!lst_a)
		return (NULL);
	set_zero(lst_a, *argc);
	i = 1;
	while (i - 1 < *argc && argv[i])
	{
		if (!is_char_only_digits(argv[i]) || is_duplicate(lst_a, i))
			return (free(lst_a), lst_a = NULL, NULL);
		lst_a[i - 1] = ft_atoi(argv[i]);
		if (ft_atoi_long_long(argv[i++]) > 2147483647 \
		|| ft_atoi_long_long(argv[i - 1]) < -2147483648)
			return (free(lst_a - (i - 1)), NULL);
	}
	lst->len_a = i;
	lst->max_len = i;
	if (is_duplicate(lst_a, i))
		return (free(lst_a), lst_a = NULL, NULL);
	return (lst_a);
}

int	*get_list_split(t_int_list *lst, int *argc, char **tab)
{
	int	i;
	int	*lst_a;

	if (!tab)
		return (NULL);
	*argc = get_split_size(tab) + 1;
	lst_a = malloc(*argc * sizeof(int));
	if (!lst_a)
		return (NULL);
	set_zero(lst_a, *argc);
	i = 0;
	while (i < *argc && tab[i])
	{
		if (!is_char_only_digits(tab[i]))
			return (free(lst_a), lst_a = NULL, NULL);
		lst_a[i] = ft_atoi(tab[i]);
		if (ft_atoi_long_long(tab[i++]) > 2147483647 \
		|| ft_atoi_long_long(tab[i - 1]) < -2147483648)
			return (free(lst_a), lst_a = NULL, NULL);
	}
	lst->len_a = i;
	lst->max_len = i;
	free_tab(tab);
	if (is_duplicate(lst_a, i))
		return (free(lst_a), lst_a = NULL, NULL);
	return (lst_a);
}

void	kill_lst(t_int_list *lst, t_int_list *lst_copy)
{
	if (lst)
	{
		free(lst->lst_a);
		free(lst->lst_b);
		free(lst);
	}
	if (lst_copy)
	{
		free(lst_copy->lst_a);
		free(lst_copy->lst_b);
		free(lst_copy);
	}
}
