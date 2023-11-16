/*#include "shell.h"

/**
 *read_input - read user input from the prompt.
 *
 *Return: void
 *

void read_input(char *buff)
{
        size_t buff_size = 0;

        if (getline(&buff, &buff_size, stdin) == -1)
        {
                perror("Getline failed");
                exit(EXIT_FAILURE);
        }
        print(buff);

	free(buff);
}*/
