/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:39:11 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/12 08:07:09 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"

int		ft_printf(const char *string, ...);
int		print_var(char c, va_list args);
void	ft_put_unsigned_nbr_fd(unsigned int n, int fd);
int		get_len_int(int n);
void	revert_char(char *str);
void	lower_str(char *str);
int		to_hex(int n, int uppercase);
int		to_hex_unsigned(unsigned int n, int uppercase);
int		to_address(long long n);
char	*ft_itoa(int n);
void	fill_res(char *res, int len_int, long n);
char	*set_minus(char *s, int len);
void	ft_strcat(char *dst, const char *src);
void	*ft_memset(void *b, int c, size_t len);
int		get_unsigned_len(unsigned int n);
char	*ft_itoa_unsigned(unsigned int n);

#endif