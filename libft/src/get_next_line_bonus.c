/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:28:30 by jmarinho          #+#    #+#             */
/*   Updated: 2023/05/08 11:50:41 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_and_join(int fd, char *temp)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(temp, '\n') == 0 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!buffer)
			return (NULL);
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp[9999];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp[fd] = ft_read_and_join(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	line = ft_get_line(temp[fd]);
	temp[fd] = ft_new_temp(temp[fd]);
	return (line);
}
