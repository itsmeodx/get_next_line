/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:46:27 by oouaadic          #+#    #+#             */
/*   Updated: 2024/11/20 16:00:30 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static inline void	read_and_append(char **line, int fd)
{
	char		*buff;
	int			count;

	count = 1;
	buff = ft_strnew(BUFFER_SIZE);
	while (count > 0 && !ft_alt_strchr(*line, '\n'))
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			free(buff);
			*line = NULL;
			return ;
		}
		buff[count] = '\0';
		*line = ft_alt_strjoin(*line, buff);
	}
	free(buff);
}

char	*get_next_line(int fd)
{
	static char	*line[MAX_FD];
	char		*str;
	int			i;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
		return (NULL);
	read_and_append(&line[fd], fd);
	if (!line[fd])
		return (NULL);
	i = 0;
	while (line[fd][i] != '\n' && line[fd][i] != '\0')
		i++;
	if (line[fd][i] == '\0')
	{
		str = line[fd];
		if (!str[0])
			str = NULL;
		return (free(line[fd]), line[fd] = NULL, str);
	}
	str = ft_alt_strsub(line[fd], 0, i + 1, 0);
	line[fd] = ft_alt_strsub(line[fd], i + 1, ft_alt_strlen(line[fd]) - i, 1);
	if (!line[fd])
		return (NULL);
	return (str);
}
