#include "shell.h"


/**
 *main - Entry point
 *
 * Return: 0 when sucessful, 1 when error
 */

int main(void)
{
	char command[200];

	while (1)
	{
		display_prompt();
		get_command(command, 200);
		exec_command(command);
	}
}


/**
 * exec_command - execute command
 *@str: command
 *
 * Return: void
 */

void exec_command(char *str)
{
	char *delim = " \t\n", *token;
	char **av;
	int status;
	pid_t ch_pid;

	av = malloc(sizeof(char *) * 1024);
	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	if (ch_pid == 0)
	{
		token = strtok(str, delim);

		while (token)
		{
			av[0] = token;
			token = strtok(NULL, delim);
		}
		av[1] = NULL;

		if (execve(av[0], av, NULL) == -1)
			perror("./hsh");
		
		free(av);
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}

/**
 * get_command - reads a line
 * @buff: Holds the string
 * @buff-size: number of char in the string
 *
 * Return: void
 */

void get_command(char *buff, size_t buff_size)
{
	ssize_t line = getline(&buff, &buff_size, stdin);

	if (line == -1)
	{
		exit(EXIT_FAILURE);
	}
	buff[strcspn(buff, "\n")] = '\0';
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
