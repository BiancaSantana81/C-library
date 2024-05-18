/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:04:38 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/18 19:08:01 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*concatenate_characters(char *s1, char *s2)
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

char	*read_file(int fd, char *buffer, ssize_t *bytes_read)
{
	*bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
	}
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*bytes_read] = '\0';
	return (buffer);
}

char	*remaining(char *str)
{
	char	*remaining_buffer;
	char	*position_n;

	remaining_buffer = ft_strchr(str, '\n');
	if (remaining_buffer == NULL || remaining_buffer[1] == '\0')
	{
		free(str);
		return (NULL);
	}
	if (remaining_buffer[0] == '\0')
	{
		free(remaining_buffer);
		return (NULL);
	}
	position_n = ft_strdup(remaining_buffer + 1);
	free(str);
	return (position_n);
}

void	check_bytes_read(ssize_t bytes_read, char **line)
{
	if (bytes_read < 0)
	{
		free(*line);
		*line = NULL;
	}
}

size_t	find_n(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}
