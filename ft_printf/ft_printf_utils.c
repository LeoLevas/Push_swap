/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:07:27 by levasse           #+#    #+#             */
/*   Updated: 2022/12/13 07:07:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	to_address(long long n)
{
	char	*res;
	char	*base;
	int		i;

	if (n == -__LONG_MAX__ - 1L)
		return (ft_printf("0x8000000000000000"));
	if (n < 0)
		return (ft_printf("0xffffffffffffffff"));
	if (n == 0)
		return (ft_printf("(nil)"));
	base = "0123456789abcdef";
	res = malloc(17 * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (n > 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	res[i] = 0;
	revert_char(res);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(res, 1);
	free (res);
	return (i + 2);
}

int	to_hex(int n, int uppercase)
{
	char	*res;
	char	*base;
	int		i;

	if (n < 0)
		return (to_hex_unsigned((unsigned)n, uppercase));
	base = "0123456789ABCDEF";
	res = malloc(get_len_int(n) * sizeof(char) + 1);
	if (!res)
		return (0);
	i = 0;
	if (n == 0)
		res[i++] = '0';
	while (n > 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	res[i] = 0;
	revert_char(res);
	if (!uppercase)
		lower_str(res);
	ft_putstr_fd(res, 1);
	i = ft_strlen(res);
	free(res);
	return (i);
}

int	to_hex_unsigned(unsigned int n, int uppercase)
{
	char	*res;
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	res = malloc(get_unsigned_len(n) * sizeof(char) + 1);
	if (!res)
		return (0);
	i = 0;
	while (n > 0)
	{
		res[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	res[i] = 0;
	revert_char(res);
	if (!uppercase)
		lower_str(res);
	ft_putstr_fd(res, 1);
	i = ft_strlen(res);
	free(res);
	return (i);
}

void	lower_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

void	revert_char(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

int	get_len_int(int n)
{
	if (n < 10)
		return (1);
	return (1 + get_len_int(n / 10));
}

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else 
	{
		ft_put_unsigned_nbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

int get_unsigned_len(unsigned n)
{
	if (n < 10)
		return (1);
	return (1 + get_unsigned_len(n / 10));
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*res;
	int		len_int;

	len_int = get_unsigned_len(n);
	res = malloc((len_int + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len_int] = '\0';
	fill_res(res, len_int, n);
	return (res);
}
