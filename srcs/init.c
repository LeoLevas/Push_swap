/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:15:20 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/13 15:09:30 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_int_list	*init_list(int argc, char *argv[])
{
	t_int_list	*lst;

	lst = malloc(sizeof(t_int_list));
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

int	is_in_chunk(t_int_list *lst, int nbr_chunk, int nbr)
{
	int	min;
	int	max;
	int	chunk_length;
	int	index_chunk;
	int	start;
	
	max = get_highest_elem(lst->lst_a, lst->len_a);
	min = get_lowest_elem(lst->lst_a, lst->len_a);
	
	chunk_length = (lst->len_a + lst->len_b) / 20;
	index_chunk = 0;
	
	while (index_chunk < nbr_chunk && min < max)
	{
		index_chunk++;
		min += chunk_length;
	}
	if (nbr >= start && nbr < (start + chunk_length))
		return (1);
	return (0);
}


int	kill_lst(t_int_list *lst)
{
	free(lst->lst_a);
	free(lst->lst_b);
	free(lst);
	return (0);
}
