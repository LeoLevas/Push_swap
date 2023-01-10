/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:51:11 by llevasse          #+#    #+#             */
/*   Updated: 2023/01/10 13:51:07 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

static int	get_len_list(int *lst);
static int	is_sorted(int *lst);

static void	print_list(int *lstA, int *lstB, int len);
static void	swap(int *lst);
static void	push(int *lst_1, int *lst_2);
static void	rotate(int *lst);
static void	reverse_rotate(int *lst);
static void	print_list(int *lstA, int *lstB, int len);
static void	set_zero(int *lst, int len);

#endif
