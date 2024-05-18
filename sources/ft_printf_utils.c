/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:21:13 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/18 18:38:53 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	int	result;

	result = write(1, &c, 1);
	return (result);
}

int	ft_putstr(char *s)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s && s[i] != 0)
	{
		result += write (1, &s[i], 1);
		i++;
	}
	return (result);
}

int	ft_putnbase(long long n, char *base)
{
	int	result;
	int	base_size;

	result = 0;
	base_size = ft_strlen(base);
	if (n < 0)
	{
		result += ft_putchar('-');
		n = n * -1;
	}
	if (n >= base_size)
		result += ft_putnbase((n / base_size), base);
	result += ft_putchar(base[n % base_size]);
	return (result);
}

int	ft_pointer(unsigned long long n, char *base)
{
	int					result;
	unsigned long long	base_size;

	result = 0;
	base_size = ft_strlen(base);
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (n >= base_size)
		result += ft_pointer ((n / base_size), base);
	else
		result += ft_putstr("0x");
	result += ft_putchar(base[n % base_size]);
	return (result);
}
