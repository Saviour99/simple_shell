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
		get_command(command, sizeof(command));
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
	int status, i = 0;
	pid_t ch_pid;

	av = malloc(sizeof(char *) * 1024);
	if (av == NULL)
	{
		perror("Malloc");
		exit(EXIT_FAILURE);
	}

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("Fork");
		free(av);
		exit(EXIT_FAILURE);
	}
	if (ch_pid == 0)
	{
		token = strtok(str, delim);

		while (token)
		{
			av[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		av[i] = NULL;

		if (av[0] && strcmp(av[0], "exit") == 0)
			exit(EXIT_SUCCESS);

		if (strchr(av[0], '/') != NULL)
		{
			if (execve(av[0], av, NULL) == -1)
				perror("./hsh");
			i = 0;
			free(av);
			exit(EXIT_FAILURE);
		}
		else
		{
			 char *path = getenv("PATH");
			 char *path_copy = strdup(path);
			 char *dir = strtok(path_copy, ":"), *full_path;

			 while (dir != NULL) 
			 {
				full_path = malloc(strlen(dir) + strlen(av[0]) + 2);
				if (full_path != NULL) 
				{
					strcpy(full_path, dir);
					strcat(full_path, "/");
					strcat(full_path, av[0]);
				}

				if (access(full_path, X_OK) == 0) 
				{
					if (execve(full_path, av, NULL) == -1) 
					{
						perror("execve");
						exit(EXIT_FAILURE);
					}
				}
				free(full_path);
				dir = strtok(NULL, ":");
			}
			print(av[0]);
			print(": Command not found\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	free(av);
}

/**
 * get_command - reads a line
 * @buff: Holds the string
 * @buff_size: number of char in the string
 *
 * Return: void
 */

void get_command(char *buff, size_t buff_size)
{
	ssize_t line = getline(&buff, &buff_size, stdin);

	if (line == -1)
	{
		print("\n");
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
	fflush(stdout);
}
