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
	char		*arr;
	size_t		i;

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

char	*line_cutter(char **stc)
{
	char	*line;
	char	*aux_freeing;
	int		i;

	i = 0;
	aux_freeing = *stc;
	while (*stc && (*stc)[i] && (*stc)[i] != '\n')
		i++;
	if ((*stc) && (*stc)[i] == '\n')
		i++;
	line = ft_substr(*stc, 0, i);
	*stc = ft_substr(*stc, i, ft_strlen((const char *)*stc));
	if (!*stc)
		free(*stc);
	if (!line[0])
	{
		free(line);
	}
	free(aux_freeing);
	return (line);
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
/*
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
*/