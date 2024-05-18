/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:09:01 by bsantana          #+#    #+#             */
/*   Updated: 2023/11/08 11:38:58 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	int				index;

	index = 0;
	if (start >= ft_strlen(s) || len == 0)
	{
		substr = (char *)malloc(1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc (len + 1);
	if (substr == NULL || s == NULL)
		return (NULL);
	while (*s != '\0' && len > 0)
	{
		substr[index] = s[start + index];
		index++;
		len--;
	}
	substr[index] = '\0';
	return (substr);
}
