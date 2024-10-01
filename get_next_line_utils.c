/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabferna <pabferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:23:11 by pablo             #+#    #+#             */
/*   Updated: 2024/09/16 18:09:22 by pabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *leftover, char *buffer)
{
	char	*aux;

	if (ft_strlen(buffer) == 0)
		return (NULL);
	aux = ft_strjoin(leftover, buffer);
	if (!aux)
		return (NULL);
	free(leftover);
	return (aux);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;
	int		i;
	int		j;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = malloc(sizeof(char)*(size_s1 + size_s2 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size_s1)
		str[i++] = s1[j++];
	j = 0;
	while (j < size_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int	ft_strclen(const char *s, char c)
{
	int		i;

	if (!s)
		return(0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s)
{
	char	*src;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s) + 1;
	src = malloc(len * sizeof(char));
	if (src == NULL)
		return (NULL);
	while (s[i])
	{
		src[i] = s[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}
