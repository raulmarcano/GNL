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

char *get_next_line(int fd)
{
    static char remain[BUFFER_SIZE];
    static size_t remain_index;
    char *newline_position;

	remain_index = 0;
    if (remain_index == 0)
    {
        int size = read(fd, remain, BUFFER_SIZE);
    }

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
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
