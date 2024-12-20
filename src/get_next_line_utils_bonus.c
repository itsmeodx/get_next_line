/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:31:14 by oouaadic          #+#    #+#             */
/*   Updated: 2024/11/20 15:57:05 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}

size_t	ft_alt_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_alt_strjoin(const char *line, const char *buff)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!line)
		line = ft_strnew(0);
	if (!line || !buff)
		return (NULL);
	i = -1;
	j = -1;
	size = ft_alt_strlen(line) + ft_alt_strlen(buff);
	str = ft_strnew(size);
	if (!str)
	{
		free ((char *)line);
		return (NULL);
	}
	while (line[++i])
		str[i] = line[i];
	while (buff[++j])
		str[i++] = buff[j];
	free ((char *)line);
	return (str);
}

char	*ft_alt_strsub(const char *line, unsigned int start, size_t len,
		int flag)
{
	char	*sub;
	size_t	i;
	size_t	size;

	if (!line)
		return (NULL);
	i = 0;
	size = ft_alt_strlen(line);
	if (size == 0)
		return (NULL);
	sub = ft_strnew(len);
	if (!sub)
		return (NULL);
	while (i < len && start < size)
		sub[i++] = line[start++];
	if (flag)
		free((char *)line);
	return (sub);
}

char	*ft_alt_strchr(const char *line, int c)
{
	size_t	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == (char)c)
			return ((char *)line + i);
		i++;
	}
	if (line[i] == (char)c)
		return ((char *)line + i);
	return (NULL);
}
