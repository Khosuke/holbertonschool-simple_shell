#include "main.h"

/**
 * _which - look for file in the current PATH
 * This function look for file in the current PATH
 * @commandName: Name of the command
 * Return: the command path or NULL if command not found
 */
char *_which(char *commandName)
{
	char *paths = _getenv("PATH"), *path_copy = strdup(paths), *filepath;
	char **path_dir;
	int j, len;
	struct stat st;

	path_dir = split_string(path_copy, ":");
	for (j = 0; path_dir[j]; j++)
	{
		len = (strlen(path_dir[j]) + strlen(commandName));
		filepath = strdup(path_dir[j]);
		filepath = realloc(filepath, (len + 2) * sizeof(char));
		filepath = strcat(filepath, "/");
		filepath = strcat(filepath, commandName);
		if (stat(filepath, &st) == 0)
			return (filepath);
	}
	free(filepath);
	free_array_string(path_dir);
	free(path_copy);
	return (NULL);
}
