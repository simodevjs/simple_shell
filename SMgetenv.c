#include "main.h"
/**
 * _smgetenv - This is an env finder
 * @varo: variable that we want its env
 * Return: The result of the env
 */
char *_smgetenv(char *varo)
{
	char *temp, *KEY, *val, *dup;
	int j;

	for (j = 0; environ[j]; j++)
	{
		temp = _strdup(environ[j]);
		KEY = strtok(temp, "=");
		if (_strcmp(KEY, varo) == 0)
		{
			val = strtok(NULL, "\n");
			dup = _strdup(val);
			free(temp);
			return (dup);
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}
