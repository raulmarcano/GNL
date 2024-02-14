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

#ifndef BUFFER_SIZE
# define BUFFER_SIZE   10
#endif

size_t	ft_strlen(const char *str)
{
	size_t	i;
	
	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t		size;
	size_t		i;
	char		*arr;

	size = (ft_strlen(s1) + 1);
	arr = malloc(size * sizeof(char));
	i = 0;
	if (!arr)
		return (NULL);
	while (i + 1 < size)
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *)(malloc(sizeof(char) * (len + 1)));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
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
	while (s1 && s1[i] != '\0')
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		cat[i] = s2[j];
		i++;
		j++;
	}
	cat[i] = '\0';
	return (cat);
}

char	*read_n_buffer(char *stc, char *buf, int fd)
{
	int	size;
	char *aux;

	aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!aux)
		return NULL;

	while (!ft_strchr(aux, '\n'))
	{
		size = read(fd, aux, BUFFER_SIZE);
		if (size <  0)
		{
			free(aux);
			return NULL;
		}
		buf = ft_strjoin(buf, aux);
	}
	if (stc)
		buf = ft_strjoin(stc, buf);

	free (stc);
	free (aux);
	return buf;
}

char *get_next_line(int fd)
{
    static char *stc;
    char    	*buf;
    char    	*line;
	int  		i;
	int 		j;
    
	if (fd <  0 || BUFFER_SIZE <=  0 || BUFFER_SIZE == INT_MAX)
		return (NULL);

	if (!stc) 
		stc = ft_calloc(BUFFER_SIZE +  1, sizeof(char));

	buf = ft_calloc(BUFFER_SIZE +  1, sizeof(char));
	if (!buf)
		return (NULL);

	buf = read_n_buffer(stc, buf, fd);
	if (!buf || !buf[0])
	{
		free(buf);
		return (NULL);
	}

	i =  0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	line = ft_substr(buf,  0, i);
	j = 0;
	if (ft_strchr(stc, '\n'))
	{
		while (stc[j] != '\n')
			j++;
	}

	// Concatenate the remaining part of the current buffer with stc
	stc = ft_strjoin((stc + j), (buf + i + 1));
	
	return line;
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
	//system("leaks -q a.out");
    return 0;
} 
