#include "main.h"

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
