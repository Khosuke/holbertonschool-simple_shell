#include "main.h"

/**
 * _which - look for file in the current PATH
 * This function look for file in the current PATH
 * @commandName: Name of the command
 * Return: the command path or NULL if command not found
 */
char *_which(char *commandName)
{
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
	return (NULL);
}

