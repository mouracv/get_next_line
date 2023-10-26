/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:15:25 by aleperei          #+#    #+#             */
/*   Updated: 2023/06/26 11:06:48 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + (i));
		i++;
	}
	return (NULL);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(src);
	while (i < j)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		len;
	char	*new;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcpy(new + ft_strlen(new), s2);
	free(s1);
	return (new);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	k;

	if (!s)
		return (NULL);
	if (ft_strlen(s) - start >= len)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	else
		sub = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!sub)
		return (NULL);
	k = 0;
	while (s[start] != '\0' && k < len)
		sub[k++] = s[start++];
	sub[k] = '\0';
	return (sub);
}
