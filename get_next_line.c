/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:27 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/18 13:19:36 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			tmp = NULL;
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
	static char	*tmp;
	char		*line;
	char		*newl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = read_file(fd, 1, tmp);
	newl = ft_strchr(tmp, '\n');
	if (newl)
	{
		line = ft_substr(tmp, 0, (newl - tmp) + 1);
		if (!line)
			return (free(tmp), NULL);
		ft_move(tmp);
	}
	else if (ft_strlen(tmp) > 0)
	{
		line = ft_substr(tmp, 0, ft_strlen(tmp));
		tmp = free_tmp(tmp);
	}
	else if (tmp)
		tmp = free_tmp(tmp);
	return (line);
}


