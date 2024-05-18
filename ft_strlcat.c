/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:26:42 by bsantana          #+#    #+#             */
/*   Updated: 2023/11/08 11:06:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_leng;
	size_t	src_leng;

	i = 0;
	j = 0;
	dst_leng = ft_strlen(dst);
	i = dst_leng;
	src_leng = ft_strlen (src);
	if (dst_leng >= size)
		return (size + src_leng);
	while (src[j] != '\0' && j < (size - dst_leng - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[j + dst_leng] = '\0';
	return (dst_leng + src_leng);
}
