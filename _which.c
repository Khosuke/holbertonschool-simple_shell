#include "main.h"

/**
 * _which - look for file in the current PATH
 * This function look for file in the current PATH
 * @commandName: Name of the command
 * Return: the command path or NULL if command not found
 */
char *_which(char *commandName)
{
<<<<<<< HEAD
	char *paths, *filepath;
	char **path_dir;
	int i = 0, len;
	struct stat st;

	paths = strdup(_getenv_long("PATH"));
	if (paths == NULL)
	{
		return (NULL);
	}
	path_dir = split_string(paths, ":");
	while(path_dir[i])
	{
		len = strlen(path_dir[i]) + strlen(commandName);
		filepath = strdup(path_dir[i]);
		filepath = realloc(filepath, (len + 2) * sizeof(char));
		strcat(filepath, "/");
		strcat(filepath, commandName);
		if (stat(filepath, &st) == 0)
		{
			free_array(path_dir);
			free(paths);
			return (filepath);
		}
		free(filepath);
		i++;
	}
	free_array(path_dir);
	free(paths);
=======
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
>>>>>>> main
	return (NULL);
}

