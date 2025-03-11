/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_get_next_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:42:00 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 12:42:03 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd = -1;
	int		fd1;
	//int		fd2;
	// int		fd3 = -1;
	int		i;
	char	*line;

	i = 0;
	//fd = open("test", O_RDONLY);
	fd1 = open("/dev/stdin", O_RDONLY);
	// fd2 = open("empty.txt", O_RDONLY);
	//fd3 = open("test2", O_RDONLY);
	if (fd1 == -1)
	{
		printf("fluff\n");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	while (1)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
	}
	// line = get_next_line(fd2);
	// printf("%s", line);
	// free(line);
	// line = get_next_line(fd3);
	// printf("%s", line);
	// free(line);
	close(fd1);
	return (0);
}
