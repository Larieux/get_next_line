/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:41:54 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 12:41:54 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*test_old_line_gnl(char *buffer)
{
	char	*line;
	char	*ptr_n;
	int		i;

	i = 0;
	ptr_n = ft_strchr(buffer, '\n');
	if (ptr_n != NULL)
	{
		while (ptr_n[i + 1] != '\0')
		{
			buffer[i] = ptr_n[i + 1];
			i++;
		}
		buffer[i] = '\0';
	}
	line = ft_strjoin(buffer, "");
	if (!line)
		return (NULL);
	return (line);
}

bool	test_new_line_gnl(char *line)
{
	char	*ptr_n;

	if (!line || line == NULL)
		return (false);
	ptr_n = ft_strchr(line, '\n');
	if (ptr_n != NULL)
	{
		ptr_n[1] = '\0';
		return (true);
	}
	return (false);
}

char	*make_line_gnl(char *line, char *buffer, int fd, ssize_t size)
{
	char	*tmp_line;
	ssize_t	n;

	n = size;
	tmp_line = ft_strjoin(line, "");
	free (line);
	while (n == size && !test_new_line_gnl(tmp_line))
	{
		n = read(fd, buffer, size);
		if (n == -1)
			return (free(tmp_line), NULL);
		buffer[n] = '\0';
		line = ft_strjoin(tmp_line, buffer);
		free(tmp_line);
		if (!line || line[0] == '\0')
			return (free(line), NULL);
		tmp_line = ft_strjoin(line, "");
		free(line);
		if (!tmp_line || tmp_line[0] == '\0')
			return (free(tmp_line), NULL);
	}
	return (tmp_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1] = {0};
	char		*tmp_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	line = test_old_line_gnl(buffer[fd]);
	if (!line)
		return (NULL);
	tmp_line = make_line_gnl(line, buffer[fd], fd, BUFFER_SIZE);
	if (!tmp_line || tmp_line == NULL)
		return (free(tmp_line), NULL);
	line = ft_strjoin(tmp_line, "");
	free(tmp_line);
	if (!line || line[0] == '\0')
		return (NULL);
	return (line);
}
