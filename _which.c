#include "main.h"

/**
 * _which - look for file in the current PATH
 * This function look for file in the current PATH
 * @commandName: Name of the command
 * Return: the command path or NULL if command not found
 */
char *_which(char *commandName)
{
	char *paths = NULL, *path_copy = NULL, *filepath;
	char **path_dir = NULL;
	int j = 0, len = 0;
	struct stat st;

	paths = _getenv("PATH");
	path_copy = strdup(paths);
	if (path_copy == NULL)
		return (NULL);
	path_dir = split_string(path_copy, ":");
	for (j = 0; path_dir[j]; j++)
	{
		filepath = NULL;
		len = (strlen(path_dir[j]) + strlen(commandName));
		filepath = strdup(path_dir[j]);
		filepath = realloc(filepath, (len + 2) * sizeof(char));
		strcat(filepath, "/");
		strcat(filepath, commandName);
		if (stat(filepath, &st) == 0)
		{
			free(path_copy);
			free_array(path_dir);
			return (filepath);
		}
		free(filepath);
	}
	free(path_copy);
	free_array(path_dir);
	return (NULL);
}
