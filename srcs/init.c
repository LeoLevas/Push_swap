/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:15:20 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/14 10:49:37 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_int_list	*init_list(int argc, char *argv[])
{
	t_int_list	*lst;

	lst = malloc(sizeof(t_int_list));
	if (!lst)
		return (NULL);
	lst->lst_a = get_list(lst, argc, argv);
	if (!lst->lst_a)
		return (free(lst), NULL);
	lst->lst_b = malloc((argc) * sizeof(int));
	if (!lst->lst_b)
	{
		free(lst->lst_a);
		return (free(lst), NULL);
	}
	set_zero(lst->lst_b, argc - 1);
	lst->ptr_a = &lst->len_a;
	lst->len_b = 0;
	lst->ptr_b = &lst->len_b;
	if (is_duplicate(lst->lst_a))
	{
		kill_lst(lst);
		lst = NULL;
	}
	return (lst);
}

int	kill_lst(t_int_list *lst)
{
	free(lst->lst_a);
	free(lst->lst_b);
	free(lst);
	return (0);
}
