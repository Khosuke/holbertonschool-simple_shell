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
	int i = 0, j = 0, token_count = 1;
	char *token, **array_token;

/* count the number of words in the buffer */
	while (buffer[i] != '\0')
	{
		if (buffer[i] == separator[0])
			token_count++;
		i++;
	}
/* memory allocation for array_token */
	array_token = malloc(1 + token_count * sizeof(char *));
	if (array_token == NULL)
		return (NULL);
/* attributing words in the buffer as token value */
	token = strtok(buffer, separator);
/* attributing each word as a string in array_token */
	while (token != NULL)
	{
		array_token[j] = strdup(token);
		if (array_token[j] == NULL)
		{
			while (j > 0)
			{
				free(array_token[j]);
				j--;
			}
			free(array_token);
			return (NULL);
		}
		token = strtok(NULL, separator);
		j++;
	}
	array_token[j] = NULL;

	return (array_token);
}
