/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarcano <rmarcano@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:46:44 by rmarcano          #+#    #+#             */
/*   Updated: 2024/02/08 17:46:59 by rmarcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;
	int		i;

	arr = malloc(count * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

char	*read_n_buffer(char *buf, int fd)
{
	int		size;
	char	*aux;

	size = 1;
	aux = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!aux)
		return (NULL);
	while (!buf || (!ft_strchr(aux, '\n') && size != 0))
	{
		size = read(fd, aux, BUFFER_SIZE);
		if (size < 0)
		{
			free(aux);
			free(buf);
			return (NULL);
		}
		aux[size] = '\0';
		buf = ft_strjoin(buf, aux);
	}
	free (aux);
	return (buf);
}

char	*line_cutter(char **s)
{
	char	*save;
	char	*aux;
	int		i;

	i = 0;
	aux = *s;
	while (*s && (*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s) && (*s)[i] == '\n')
		i++;
	save = ft_substr(*s, 0, i);
	*s = ft_substr(*s, i, ft_strlen((const char *)*s));
	if (!*s)
		free(*s);
	free(aux);
	if (!save[0])
	{
		free(save);
		save = NULL;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*stc;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	stc = read_n_buffer(stc, fd);
	if (!stc || !stc[0])
	{
		free(stc);
		stc = NULL;
		return (NULL);
	}
	line = line_cutter(&stc);
	return (line);
}


int main()
{	int	fd;
	char *line;

	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s\n", line);
        free(line);
    }

    close(fd);
	system("leaks -q a.out");
    return 0;
} 
