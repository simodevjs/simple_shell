#include "main.h"

char *_smpath(char *comodo)
{
	char *penv, *fullcmd, *rep;
	int i;
	struct stat st;



	for (i = 0; comodo[i]; i++)
	{
		if (comodo[i] == '/')
		{
			if (stat(comodo, &st) == 0)
				return (_strdup(comodo));
			return (NULL);
		}
	}

	penv = _smgetenv("PATH");
	if (!penv)
		return (NULL);

	rep = strtok(penv, ":");

	while (rep)
	{
		fullcmd = malloc(_strlen(rep) + _strlen(comodo) + 2);
		if (fullcmd)
		{
			_strcpy(fullcmd, rep);
			_strcat(fullcmd, "/");
			_strcat(fullcmd, comodo);
			if (stat(fullcmd, &st) == 0)
			{
				free(penv);
				return (fullcmd);
			}
			free(fullcmd), fullcmd = NULL;
			rep = strtok(NULL, ":");
		}
	}
	free(penv);
	return (NULL);
}
