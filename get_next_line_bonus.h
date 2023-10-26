/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:34:59 by aleperei          #+#    #+#             */
/*   Updated: 2023/06/27 14:02:06 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

# ifndef MAX_FD
#  define MAX_FD 10000
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		check_nl(char *buffer);

char	*get_next_line(int fd);
char	*free_tmp(char *tmp);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*read_file(int fd, int byte, char *tmp);

void	ft_strcpy(char *dest, char *src);
void	ft_move(char *str);

#endif