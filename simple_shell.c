#include "main.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: Always 0 (Success)
 */
int main(int ac, char *av[])
{
	size_t size;
	ssize_t read;
	pid_t child;
	int status;
	char *buffer, *commandPath;
	(void)ac;

	while (1)
	{
		printf("simple_shell $ ");
		read = getline(&buffer, &size, stdin);
		if (read != -1)
		{
			child = fork();
			if (child == -1)
			{
				perror("Error");
				return (1);
			}
			if (child == 0)
			{
				if (buffer[read - 1] == '\n')
					buffer[read - 1] = '\0';
				av = split_string(buffer, " ");
				if (av[0][0] != '/')
					commandPath = _which(av[0]);
				else
					commandPath = av[0];
				if (strcmp(av[0], "exit") == 0)
				{
					free(buffer);
					free_array(av);
					free(commandPath);
					kill(child, 15);
				}
				if (execve(commandPath, av, environ) == -1)
					perror("Error");
			}
			else
				wait(&status);
		}
	}
	return (0);
}
