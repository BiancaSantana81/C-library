/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:50:31 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/25 17:31:48 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*result;
	size_t		i;
	size_t		j;
	size_t		s1_len;
	size_t		s2_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc (((s1_len + s2_len + 1)) + 1 * sizeof(char));
	if (!result)
		return (NULL);
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (j <= s2_len)
		result[i++] = s2[j++];
	result[(s1_len + s2_len + 1)] = '\0';
	s1 = NULL;
	return (result);
}
