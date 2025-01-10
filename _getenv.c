#include "main.h"

/**
 * _getenv - gets an environment variable
 * @name: name of the variable to get the value
 * Return: the value of the variable or NULL if the variable is not found
 */
char *_getenv(const char *name)
{
	char *token_env;
	int i = 0, len_name = 0, j = 0, len_env = 0;

	len_name = strlen(name);
	for (i = 0; environ[i]; i++)
	{
		len_env = strlen(environ[i]);
		for (j = 0; j <= len_name; j++)
		{
			if (strncmp(name, environ[i], len_name) == 0)
			{
				token_env = malloc(sizeof(char) * (len_env - len_name + 1));
				strcpy(token_env, &environ[i][len_name + 1]);
				return (token_env);
			}
		}
	}
	return (NULL);
}
