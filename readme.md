<h2 align="center">📚 Welcome to:</h2>
<h1 align="center">get_next_line - A Line Reading Utility</h1>

<p style="text-align: justify;" align="center">
  This project provides a simple and efficient implementation of the <b>get_next_line</b> function in C. The function allows you to read a line, one by one, from a file descriptor, making it useful for parsing and handling text files in your C programs.
</p>

<h3 align="center">Languages and Tools:</h3>
<p align="center">
    <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/>
    <img src="https://www.vectorlogo.zone/logos/git-scm/git-scm-icon.svg" alt="git" width="40" height="40"/>
</p>

## Installation

To use the `get_next_line` function in your project, follow these steps:

1. Clone the repository in the same directory of the file you want to read(fd).
2. In the main function, change "test.txt" for the name of your fd.
3. Compile `get_next_line.c` file (like the example below).
4. If you wish to read a specific number of lines, modify the loop in the main function to iterate according to your requirements.
   
Example compilation and execution command:
```bash
gcc -Wall -Wextra -Werror get_next_line_utils.c get_next_line.c -o executable_name && ./executable_name
```
## Features

- Reads lines from a file descriptor.
- Allows to modify the BUFFER_SIZE.
- Handles dynamic memory allocation for variable-length lines.
- Easily integrates into C projects for text file processing.

## Bonus Features

- Manages multiple file descriptors simultaneously using only one static variable.
- Allows reading from different file descriptors without losing the reading thread of each.
- Supports reading from various file descriptors in a sequential manner.


