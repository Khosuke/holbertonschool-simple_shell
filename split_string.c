#include "main.h"

/**
 * split_string - split a string and returns an array of each
 * word of the string
 * @buffer: the string to split
 * @separator: the separator to use
 * Return: an array of each word of the string
 */
char **split_string(char *buffer, char *separator)
{
	int j = 0, token_count = 0;
	char *token, **array_token, *buffer_copy;

	buffer_copy = strdup(buffer);
	if (buffer_copy == NULL)
		return (NULL);
	token = strtok(buffer_copy, separator);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, separator);
	}
	array_token = malloc((token_count + 1) * sizeof(char *));
	if (array_token == NULL)
	{
		free(buffer_copy);
		return (NULL);
	}
	strcpy(buffer_copy, buffer);
	token = strtok(buffer_copy, separator);
	while (token != NULL)
	{
		array_token[j] = strdup(token);
		if (array_token[j] == NULL)
		{
			while (j > 0)
			{
				free(array_token[j - 1]);
				j--;
			}
			free(array_token), free(buffer_copy);
			return (NULL);
		}
		token = strtok(NULL, separator);
		j++;
	}
	array_token[j] = NULL;
	free(buffer_copy);
	return (array_token);
}
