#include "main.h"

/**
 * free_array_string - free an array of strings
 * @array: the array to free
 */
void free_array_string(char **array)
{
	int i = 0;

	if (array == NULL)
		return;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
