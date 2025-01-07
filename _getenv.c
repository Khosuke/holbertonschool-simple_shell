#include "main.h"

/**
 * _getenv - gets an environment variable
 * @name: name of the variable to get the value
 * Return: the value of the variable or NULL if the variable is not found
 */
char *_getenv(const char *name)
{
	char *token_env = NULL, *dupEnviron = NULL;
	int i;

	for (i = 0; environ[i]; i++)
	{
		dupEnviron = strdup(environ[i]);
		token_env = strtok(dupEnviron, "=");
		if (token_env != NULL && strcmp(token_env, name) == 0)
		{
			token_env = strtok(NULL, "=");
			free(dupEnviron);
			return (token_env);
		}
		free(dupEnviron);
	}
	free(token_env);
	return (NULL);
}
