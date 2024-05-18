/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:58:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/18 17:46:27 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy( char *dst, const char *src, size_t size)
{
	size_t			src_leng;
	unsigned int	i;

	i = 0;
	src_leng = ft_strlen(src);
	if (size == 0)
		return (src_leng);
	while (i < size -1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_leng);
}
