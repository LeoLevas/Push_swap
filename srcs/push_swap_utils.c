/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:30:03 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/14 17:52:38 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sorted(int *lst, int len_arr)
{
	int	i;

	i = 1;
	while (lst[i] >= lst[i - 1] && i <= len_arr - 1)
		i++;
	if (lst[i] < lst[i - 1])
		return (0);
	return (1);
}

int	is_duplicate(int *lst, int len_arr)
{
	int	i;
	int	j;

	i = 0;
	while (i <= len_arr)
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


#include <stdio.h>
int main()
{
	int lst[] = {1, 2, 3, 4};
	int lst2[] = {1, 4, 4, 3};

	printf("lst1 : %i | lst2 : %i\n", is_sorted(lst, 3), is_sorted(lst2, 3));
	printf("lst1 : %i | lst2 : %i\n", is_duplicate(lst, 3), is_duplicate(lst2, 3));
}