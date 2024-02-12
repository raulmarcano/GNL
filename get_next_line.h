#ifndef get_next_line_H
# define get_next_line_H

	//Define static variable
#ifndef BUFFER_SIZE
# define BUFFER_SIZE  10 //Asign default value
#endif

char    *get_next_line(int fd);

#endif
