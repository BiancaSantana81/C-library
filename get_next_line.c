/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:52:56 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/18 17:03:53 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		bytes_read;

	bytes_read = 0;
	line = NULL;
	if (buffer)
	{
		line = ft_strjoin(NULL, buffer);
		if (!ft_strchr(buffer, '\n'))
		{
			free(buffer);
			buffer = NULL;
		}
	}
	while ((!ft_strchr(buffer, '\n')))
	{
		buffer = read_file(fd, buffer, &bytes_read);
		if (!buffer)
			break ;
		line = ft_strjoin(line, buffer);
	}
	check_bytes_read(bytes_read, &line);
	buffer = remaining(buffer);
	return (line);
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
