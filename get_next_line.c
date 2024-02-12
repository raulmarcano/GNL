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
	char	*buf;

	buf = ft_calloc(BUFFER_SIZE, sizeof(char))

	read(fd, buf);

}

int main()
{
	fd = open("./test");
	if (fd == -1)
	{
		/*error*/
	}
}
