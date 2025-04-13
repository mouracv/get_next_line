/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:34:41 by aleperei          #+#    #+#             */
/*   Updated: 2023/06/27 14:01:56 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_nl(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_move(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		i++;
		while (str[i] != '\0')
			str[j++] = str[i++];
		str[j] = str[i];
	}
}

char	*read_file(int fd, int byte, char *tmp)
{
	char	*r_buffer;

	r_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!r_buffer)
	{
		free(r_buffer);
		free(tmp);
		return (NULL);
	}
	while (check_nl(tmp) == 0 && byte > 0)
	{
		byte = read(fd, r_buffer, BUFFER_SIZE);
		if (byte < 0)
		{
			free(r_buffer);
			free(tmp);
			return (NULL);
		}
		r_buffer[byte] = '\0';
		tmp = ft_strjoin_free(tmp, r_buffer);
	}
	free(r_buffer);
	return (tmp);
}

char	*free_tmp(char *tmp)
{
	free(tmp);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*tmp[MAX_FD];
	char		*line;
	char		*newl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp[fd] = read_file(fd, 1, tmp[fd]);
	newl = ft_strchr(tmp[fd], '\n');
	if (newl)
	{
		line = ft_substr(tmp[fd], 0, (newl - tmp[fd]) + 1);
		if (!line)
			return (free(tmp[fd]), NULL);
		ft_move(tmp[fd]);
	}
	else if (ft_strlen(tmp[fd]) > 0)
	{
		line = ft_substr(tmp[fd], 0, ft_strlen(tmp[fd]));
		tmp[fd] = free_tmp(tmp[fd]);
	}
	else if (tmp[fd])
		tmp[fd] = free_tmp(tmp[fd]);
	return (line);
}
