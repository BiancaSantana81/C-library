/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:52:56 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/18 19:08:09 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		bytes_read;

	bytes_read = 0;
	line = NULL;
	if (buffer)
	{
		line = concatenate_characters(NULL, buffer);
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
		line = concatenate_characters(line, buffer);
	}
	check_bytes_read(bytes_read, &line);
	buffer = remaining(buffer);
	return (line);
}
