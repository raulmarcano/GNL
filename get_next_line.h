#ifndef get_next_line_H
# define get_next_line_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

	//Define standar buffer_size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   20
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char 	*search_line_cpy(char *buf, char *remain);

#endif
