#include "main.h"

/**
 * _which - look for file in the current PATH
 * This function look for file in the current PATH
 * @commandName: Name of the command
 * Return: the command path or NULL if command not found
 */
char *_which(char *commandName)
{
	char *paths = NULL, *filepath;
	char **path_dir = NULL;
	int j = 0, len = 0;
	struct stat st;

	paths = _getenv("PATH");
	path_dir = split_string(paths, ":");
	if (path_dir == NULL)
	{
		free(paths);
		return (NULL);
	}
	for (j = 0; path_dir[j]; j++)
	{
		len = (strlen(path_dir[j]) + strlen(commandName) + 2);
		filepath = malloc(len * sizeof(char));
		if (filepath == NULL)
		{
			free(paths);
			free_array(path_dir);
			return (NULL);
		}
		strcpy(filepath, path_dir[j]);
		strcat(filepath, "/");
		strcat(filepath, commandName);
		if (stat(filepath, &st) == 0)
		{
			free(paths);
			free_array(path_dir);
			return (filepath);
		}
		free(filepath);
		filepath = NULL;
	}
	free(paths);
	free_array(path_dir);
	return (NULL);
}

