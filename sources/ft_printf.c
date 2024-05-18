/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:05:13 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/18 18:38:44 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *type_format, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!type_format)
		return (-1);
	va_start(args, type_format);
	while (type_format[i])
	{
		if (type_format[i] == '%' && type_format[i + 1] != '\0')
			result += ft_flags(type_format[++i], args);
		else
			result += ft_putchar(type_format[i]);
		i++;
	}
	va_end(args);
	return (result);
}

int	ft_flags(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (flag == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (flag == 'p')
		return (ft_pointer(va_arg(args, unsigned long long), HEXA_LOWER_BASE));
	if (flag == 'd' || flag == 'i')
		return (ft_putnbase(va_arg(args, int), DECIMAL_BASE));
	if (flag == 'x')
		return (ft_putnbase(va_arg(args, unsigned int), HEXA_LOWER_BASE));
	if (flag == 'X')
		return (ft_putnbase(va_arg(args, unsigned int), HEXA_UPPER_BASE));
	if (flag == '%')
		return (ft_putchar('%'));
	if (flag == 'u')
		return (ft_putnbase(va_arg(args, unsigned int), DECIMAL_BASE));
	return (0);
}
