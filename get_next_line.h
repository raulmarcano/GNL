#ifndef get_next_line_H
# define get_next_line_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

	// Define standar buffer_size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   30
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*read_n_buffer(char *buf, int fd);
char 	*get_next_line(int fd);
char	*line_cutter(char **s);

#endif
