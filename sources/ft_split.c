/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:05:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/18 17:48:43 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numbers_words(const char *s, char c)
{
	size_t	count;
	size_t	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

static void	word_len(const char *s, char c, char **matrix)
{
	int		index;
	int		len;
	int		p;

	index = 0;
	p = 0;
	while (s[index])
	{
		len = 0;
		if (s[index] == c)
			index++;
		while (s[index] != c && s[index])
		{
			len++;
			index++;
		}
		if (len > 0)
		{
			matrix[p] = (char *)ft_calloc(len + 1, sizeof(char));
			p++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**word_memory;
	int		word_count;
	int		i;
	int		j;
	int		k;

	word_count = numbers_words(s, c);
	word_memory = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!word_memory)
		return (NULL);
	word_len(s, c, word_memory);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[j] == c && s[j])
			j++;
		k = 0;
		while (s[j] != c && s[j])
			word_memory[i][k++] = s[j++];
		i++;
	}
	return (word_memory);
}
