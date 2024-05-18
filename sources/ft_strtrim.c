/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:40:04 by bsantana          #+#    #+#             */
/*   Updated: 2023/11/08 11:43:14 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*result;

	first = 0;
	last = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[first]) && first <= last)
		first++;
	if (first > last)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[last]) && last >= 0)
		last--;
	result = malloc(last - first + 2);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s1[first], last - first + 2);
	return (result);
}
