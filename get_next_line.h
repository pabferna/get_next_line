/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:56:30 by pablo             #+#    #+#             */
/*   Updated: 2024/09/05 12:49:39 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*buffer_read(int fd, char *leftover);
char	*ft_result(char *leftover);
char	*ft_free(char *leftover, char *buffer);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);

int		ft_strclen(const char *str, char c);
int		ft_strlen(const char *str);

#endif