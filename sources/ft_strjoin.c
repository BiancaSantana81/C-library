/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:50:31 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/18 17:03:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*result;
	size_t		i;
	size_t		j;
	size_t		s1_len;
	size_t		find_n_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	find_n_len = find_n(s2);
	result = malloc (((s1_len + find_n_len + 1)) + 1 * sizeof(char));
	if (!result)
		return (NULL);
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (j <= find_n_len)
		result[i++] = s2[j++];
	result[(s1_len + find_n_len + 1)] = '\0';
	free(s1);
	s1 = NULL;
	return (result);
}
