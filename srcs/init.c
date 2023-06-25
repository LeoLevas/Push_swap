/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:15:20 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/25 17:54:10 by llevasse         ###   ########.fr       */
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
	lst->lst_b = malloc((argc) * sizeof(int));
	if (!lst->lst_b)
	{
		free(lst->lst_a);
		return (free(lst), NULL);
	}
	set_zero(lst->lst_b, argc - 1);
	lst->len_b = 0;
	if (is_duplicate(lst->lst_a, lst->len_a))
	{
		kill_lst(lst);
		lst = NULL;
	}
	return (lst);
}

int	*get_list(t_int_list *lst, int *argc, char *argv[])
{
	int	*lst_a;
	int	i;

	if (*argc == 1)
		return (0);
	if (*argc == 2)
		return (get_list_split(lst, argc, ft_split(argv[1], " ")));
	lst_a = malloc((*argc) * sizeof(int));
	if (!lst_a)
		return (NULL);
	set_zero(lst_a, *argc - 1);
	i = 0;
	while (i++ < *argc && argv[i] && is_char_only_digits(argv[i]))
	{
		*lst_a++ = ft_atoi(argv[i]);
		if (ft_atoi_long_long(argv[i]) > 2147483647 \
		|| ft_atoi_long_long(argv[i]) < -2147483648)
			return (free(lst_a - i), NULL);
	}
	lst_a -= (i - 1);
	lst->len_a = i - 1;
	lst->max_len = i - 1;
	if (!is_char_only_digits(argv[i]))
		return (free(lst_a), NULL);
	return (lst_a);
}

int	*get_list_split(t_int_list *lst, int *argc, char **tab)
{
	int	i;
	int	*lst_a;

	*argc = get_split_size(tab);
	lst_a = malloc(*argc * sizeof(int));
	if (!lst_a)
		return (NULL);
	set_zero(lst_a, *argc);
	i = 0;
	while (i++ < *argc && tab[i] && is_char_only_digits(tab[i]))
	{
		*lst_a++ = ft_atoi(tab[i]);
		if (ft_atoi_long_long(tab[i]) > 2147483647 \
		|| ft_atoi_long_long(tab[i]) < -2147483648)
			return (free(lst_a - i), NULL);
	}
	lst_a -= (i - 1);
	lst->len_a = i - 1;
	lst->max_len = i - 1;
	free_tab(tab);
	return (lst_a);
}

int	kill_lst(t_int_list *lst)
{
	free(lst->lst_a);
	free(lst->lst_b);
	free(lst);
	return (0);
}
