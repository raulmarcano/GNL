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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		mem[i] = c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;

	arr = malloc(count * size);
	if (arr == NULL)
		return (NULL);
	ft_memset(arr, 0, (count * size));
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	cat_len;
	size_t	i;
	size_t	j;
	char	*cat;

	cat_len = ((ft_strlen(s1)) + (ft_strlen(s2)) + 1);
	cat = (char *)malloc(cat_len);
	if (cat == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		cat[i] = s2[j];
		i++;
		j++;
	}
	cat[i] = '\0';
	return (cat);
}

char	*read_n_buffer(char *buf, int fd)
{
	int	size;
	char *aux;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buf)
        return NULL;
	while (!aux || (!ft_strchr(aux, '\n')))
	{
		size = read(fd, aux, BUFFER_SIZE);
		if (size < 0)
		{
			free(buf);
			return NULL;
		}
	}
	buf = ft_strjoin(buf, aux);
	free(aux);
	return (buf);
}

char *get_next_line(int fd)
{
    static char *stc;
    char    	*buf;
    char    	*line;
    
	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	buf = read_n_buffer(buf, fd);
	if (!buf || !buf[0])
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
    return line;
}

int main()
{	int	fd;
	char *line;

	fd = open("./test", O_RDONLY);
	if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    if ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s\n", line);
        free(line);
    }

    close(fd);
    system("leaks -q a.out");
    return 0;
}
