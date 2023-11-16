#include "shell.h"

/**
 *main - Entry point.
 *@argc: argument count
 *@argv: argument vector

 *Return: 0 on sucess and 1 when it's an error.
 */

int main(__attribute__((unused))int argc, char *argv[])
{
	size_t buff_size = 0;
	char *buff = NULL, *token, **arr;
	pid_t kid_pid;
	int status, i = 0;
	bool pipe = false;

	while (1 && !pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe = true;
		display_prompt();
		if (getline(&buff, &buff_size, stdin) == -1)
		{
			perror(argv[0]);
			free(buff);
			exit(EXIT_FAILURE);
		}
		arr = malloc(sizeof(char *) * 1024);
		token = strtok(buff, " \t\n");
		while (token)
		{
			arr[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		kid_pid = fork();
		if (kid_pid == 0)
		{
			execve(arr[0], arr, NULL);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
		i = 0;
	}
	free(arr);
	return (0);
}

/**
 *print - print a string
 *@string: string of characters
 *
 * Return: void
 */

void print(char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}

/**
 *display_prompt - print the prompt
 *
 *Return: void
 */

void display_prompt(void)
{
	print("$ ");
}
