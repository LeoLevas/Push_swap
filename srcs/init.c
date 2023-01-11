/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:15:20 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/11 15:38:27 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

struct s_int_list	*init_list(int argc, char *argv[])
{
	struct s_int_list	*lst;

	lst = malloc(sizeof(struct s_int_list));
	if (!lst)
		return (NULL);
	lst->lst_a = get_list(argc, argv);
	if (!lst->lst_a)
		return (free(lst), NULL);
	lst->lst_b = malloc((argc + 1) * sizeof(int));
	if (!lst->lst_b)
	{
		free(lst->lst_a);
		return (free(lst), NULL);
	}
	set_zero(lst->lst_b, argc);
	lst->len_a = argc - 1;
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

int	kill_lst(struct s_int_list *lst)
{
	free(lst->lst_a);
	free(lst->lst_b);
	free(lst);
	return (0);
}
