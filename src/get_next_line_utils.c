/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:41:46 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/11 12:41:47 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c % 256)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *) s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src [i])
	{
		dst [i] = src [i];
		i++;
	}
	dst [i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (dst[i])
		i++;
	while (src && src[res])
		res++;
	if (size <= i)
		res += size;
	else
		res += i;
	while (i + 1 < size && src && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(size * sizeof (char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, size);
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
