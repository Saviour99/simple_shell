/*#include "shell.h"

/**
 *execute_command - execute the commad of the program
 *@str: array of strings
 *
 *Return: void
 *

void execute_command(const char *str)
{
	pid_t kid_pid;
	int status;

	kid_pid = fork();
	if (kid_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (kid_pid == 0)
	{
		if (execve(str[0], str, NULL) == -1)
		{
			perror("Execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}*/
