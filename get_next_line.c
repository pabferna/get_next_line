/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:55:35 by pablo             #+#    #+#             */
/*   Updated: 2024/09/16 23:02:44 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len) //falta una condición
{
	int		i;
	int		j;
	char	*str;

	i = start;
	j = 0;
	if (!s || len == 0)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) + i))
		len = ft_strlen(s) + i;
	str = malloc(sizeof (char) * (len + 1));
	if (!str)
		return (NULL);
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_result(char *leftover)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!leftover)
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	while (leftover[j] && leftover[j] != '\n')
	{
		result[j] = leftover[j];
		j++;
	}
	if (leftover[i] && leftover[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*buffer_read(int fd, char *leftover)
{
	char	*buffer;
	int		byte_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		if (byte_read <= 0)
		{
			free(buffer);
			buffer = NULL;
			return (leftover);
		}
		leftover = ft_free(leftover, buffer);
		if (ft_strclen(leftover, '\n') != -1)
		{
			free(buffer);
			buffer = NULL;
			break;
		}
	}
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*_static;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (_static == NULL || ft_strlen(_static) == 0)
	{
		_static = buffer_read(fd, _static);
		if (!_static)
		{
			free(_static);
			_static = NULL;
			return (NULL);
		}
	}
	result = ft_result(_static);
	if (ft_strclen(_static, '\n') + 1 == '\0')
	{
		free(_static);
		_static = NULL;
		return(result);
	}
	if (!result)
		return (NULL);
	if (ft_strclen(_static, '\n') == -1)
		_static = NULL;
	_static = ft_substr(_static, ft_strclen(_static, '\n') + 1, ft_strlen(_static) - (ft_strclen(_static, '\n') + 1));
	return (result);
}

int main(void)
{
    // const char *filename = "tt.txt"; // Nombre del archivo a leer
    int fd = open("tt.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // close(fd);
	// char *line = get_next_line(fd);
	// printf("%s\n", line);

	// free(line);

	// line = get_next_line(fd);
	// printf("%s\n", line);
	// free(line);
	
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("~%s~\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
    return 0;
}