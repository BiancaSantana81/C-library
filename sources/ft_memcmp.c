/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:26:05 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/18 17:49:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*sh1;
	const unsigned char		*sh2;

	i = 0;
	sh1 = s1;
	sh2 = s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (sh1[i] != sh2[i])
			return (sh1[i] - sh2[i]);
		i++;
	}
	return (0);
}
