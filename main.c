#include "main.h"
extern char **environ;

/**
 * simpleshell - Super Simple Shell 
 * 
 * Return: always 0
 */
int simpleshell(void)
{
	pid_t child;
	ssize_t read;
	size_t n = 0;
	int status;
	char *buffer, **argv, *commandPath;
	
	read = getline(&buffer, &n, stdin);
	if (read != -1)
	{
		if(buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';
		argv = split_string(buffer, " ");
		if (argv[0][0] != '/')
				commandPath = _which(argv[0]);
			else
				commandPath = argv[0];
		if(strcmp((argv[0]), "exit") == 0)
		{
			exit(98);
		}
		if (commandPath != NULL)
		{
			child = fork();
			if (child == -1)
			{
        		perror("Error:");
        		return (1);
    		}
			if (child == 0)
			{
				if (execve(commandPath, argv, environ) == -1)
				{
					perror("Error:");
				}
			}
			wait(&status);
		}
		else
		{
			printf("Command %s does not exist\n", argv[0]);
		}
	}
	free_array(argv);
	free(buffer);
	return (0);
}


/**
 * main - Super Simple Shell
 * 
 * Return: No return
 */
int main (int ac, char **av)
{
	(void) **av;
	(void) ac;

	if (isatty(STDIN_FILENO) == 0)
	{
		simpleshell();		
	}
	else
	{
		while (1)
		{
			printf("SuperShell $ ~");
			simpleshell();
		}
	}
	return(0);
}
