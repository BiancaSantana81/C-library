/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:32:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/18 17:49:58 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			i;
	unsigned char			b;
	unsigned char			*sh;

	i = c;
	b = 0;
	sh = (unsigned char *)s;
	while (b < n)
	{
		if (sh[b] == i)
			return ((void *)(sh + b));
		b++;
	}
	return (NULL);
}
