#include "main.h"

/**
 * forkexec - fork and execute command
 * @commandPath: Path of the command
 * @cmd: The command
 * Return: Always 0
 */
int forkexec(char *commandPath, char **cmd)
{
	pid_t child;
	int status = 0;

	child = fork();
	if (child == -1)
	{
		perror("Error");
		return (-1);
	}
	if (child == 0)
	{
		if (execve(commandPath, cmd, environ) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	wait(&status);
	return (0);
}

/**
 * checkCommand - Handle the user input
 * @buffer: user input
 * @av: Name of the program
 * Return: The return status of the executed command (0 on Success)
 */
int checkCommand(char *buffer, char **av)
{
	char **cmd, *commandPath, *delimiter = " \n";
	int status = 0;

	cmd = split_string(buffer, delimiter);
	if (cmd == NULL)
	{
		free(buffer);
		return (1);
	}
	if (cmd[0][0] != '/')
		commandPath = _which(cmd[0]);
	else
		commandPath = cmd[0];
	if (strcmp(cmd[0], "exit") == 0)
	{
		free(buffer);
		free_array(cmd);
		exit(0);
	}
	if (commandPath != NULL)
	{
		status = forkexec(commandPath, cmd);
		if (cmd[0][0] != '/')
			free(commandPath);
	}
	else
	{
		fprintf(stderr, "%s: 1: %s: not found\n", *av, *cmd);
		free_array(cmd);
		return (127);
	}
	free_array(cmd);
	return (status);
}

/**
 * shell - execute the command
 * @av: name of the program
 * Return: The return status of the executed command (0 on Success)
 */
int shell(char **av)
{
	size_t size = 0;
	ssize_t read;
	char *buffer = NULL;
	int status = 0;

	read = getline(&buffer, &size, stdin);
	if (read != -1)
	{
		if (buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';
		if (*buffer == '\0' || strcmp(buffer, " ") == 0)
		{
			free(buffer);
			return (0);
		}
		status = checkCommand(buffer, av);
	}
	else
	{
		free(buffer);
		printf("\n");
		exit(0);
	}
	free(buffer);
	return (status);
}

/**
 * main - Entry point
 * @ac: argument count
 * @av: name of the program
 * Return: The return status of the executed command (0 on Success)
 */
int main(int ac, char **av)
{
	int status = 0;
	(void)ac;

	if (isatty(0) == 0)
	{
		status = shell(av);
		return (status);
	}

	while (1)
	{
		printf("Simple Shell $ ");
		status = shell(av);
		if (status != 0)
			break;
	}
	return (status);
}
