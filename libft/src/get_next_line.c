/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:05:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:29 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <fcntl.h>

char	*delete_line(char *nw_line)
{
	int		i;
	int		j;
	char	*left;

	if (nw_line[0] == '\0')
	{
		free(nw_line);
		return (NULL);
	}
	i = 0;
	while (nw_line[i] != '\n' && nw_line[i])
		i++;
	left = (char *)malloc((ft_strlen(nw_line) - i + 1) * sizeof(char));
	if (left == NULL)
		return (NULL);
	j = 0;
	if (nw_line[i] == '\n')
		i++;
	while (nw_line[i] != '\0')
		left[j++] = nw_line[i++];
	left[j] = '\0';
	free(nw_line);
	return (left);
}

char	*line(char *nw_line)
{
	char	*line;
	int		i;

	if (nw_line[0] == '\0')
		return (NULL);
	i = 0;
	while (nw_line[i] != '\n' && nw_line[i])
		i++;
	if (nw_line[i] == '\n')
		line = (char *)malloc(sizeof(char) * i + 2);
	else
		line = (char *)malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (nw_line[i] != '\n' && nw_line[i])
	{
		line[i] = nw_line[i];
		i++;
	}
	if (nw_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*readed(char *nw_line, int fd)
{
	int		size;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	size = 1;
	while (ft_strchr_get(nw_line, '\n') == NULL && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(nw_line);
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		nw_line = ft_strjoin_get(nw_line, buffer);
	}
	free(buffer);
	return (nw_line);
}

char	*get_next_line(int fd)
{
	static char	*nw_line;
	char		*fline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
	{
		nw_line = readed(nw_line, fd);
		if (nw_line == NULL)
			return (NULL);
		else
		{
			fline = line(nw_line);
			nw_line = delete_line(nw_line);
			return (fline);
		}
	}
}

/* int main()
{
	int		i = 0;
	int		fd;
	char	*a;

	fd = open ("/nfs/homes/rumachad/42Curso/get_next_line/test.txt", O_RDWR);
	while (i < 8)
	{
		a = get_next_line(fd);
		printf("%s", a);
		free(a);
		i++;
	}
	close (fd);
} */

/* int main()
{
	int i = 0;
	char *a;
	
	while (i < 2)
	{
		a = get_next_line(0);
		printf("Function output: %s", a);
		free(a);
		i++;
	}
} */
