#include "main.h"

/**
 * forkexec - fork and execute command
 * Return: Always 0
 */
int forkexec(char *commandPath, char **cmd)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("Error");
		return (1);
	}
	if (child == 0)
	{
		if (execve(commandPath, cmd, environ) == -1)
			perror("Error");
	}
	wait(&status);
	return (0);
}

/**
 * shell - execute the command
 * Return: Always 0 (Success)
 */
int shell(void)
{
	size_t size;
	ssize_t read;
	char *buffer, *commandPath, **cmd;

	read = getline(&buffer, &size, stdin);
	if (read != -1)
	{
		if (buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';
		cmd = split_string(buffer, " ");
		free(buffer);
		if (cmd[0][0] != '/')
			commandPath = _which(cmd[0]);
		else
			commandPath = cmd[0];
		if (strcmp(cmd[0], "exit") == 0)
		{
			free_array(cmd);
			free(commandPath);
			exit(99);
		}
		if (commandPath != NULL)
		{
			forkexec(commandPath, cmd);
			free(commandPath);
		}
		else
		{
			free(commandPath);
			perror("Error");
		}
	}
	free_array(cmd);
	free(commandPath);
	free(buffer);
	return (0);
}

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	if (isatty(0) == 0)
		shell();
	else
		while (1)
		{
			printf("simple_shell $ ");
			shell();
		}
	return (0);
}
