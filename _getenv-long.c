#include "main.h"
#include <stdlib.h>

/**
 * _getenv_long - get an environment variable
 * @name: name of the environment variable we want to get
 *
 * Return: the
 */
char *_getenv_long(char *name)
{
	char **array_getenv, **token_env, *ptr_token, *delimiter = "=";
	int i = 0, j = 0, n = 0, a = 0;

	while (environ[i])
		i++;
	array_getenv = malloc(sizeof(char *) * i + 1);
	if (array_getenv == NULL)
		return (NULL);
	token_env = malloc(sizeof(char *) * (i + 1) * 2);
	if (token_env == NULL)
		return (NULL);
	i = 0;
	/* duplicate environ into a new array */
	while (environ[i])
	{
		array_getenv[i] = strdup(environ[i]);
		i++;
	}
	while (array_getenv[j])
	{
		ptr_token = strtok(array_getenv[j], delimiter);
		token_env[n] = strdup(ptr_token);
		n++;
		ptr_token = strtok(NULL, "\0");
		if (ptr_token == NULL)
			token_env[n] = NULL;
		else
			token_env[n] = strdup(ptr_token);
		n++;
		j++;
	}
	while (token_env[a])
	{
		if (strcmp(token_env[a], name) == 0)
		{
			free_array(array_getenv);
			return (token_env[a + 1]);
		}
		a += 2;
	}
	return (NULL);
}

