#include "main.h"

int _smbuilted(char *comodo)
{
	char *builted[] = {
		"exit", "env", "setenv", "cd", NULL
			};
	int j;

	for (j = 0; builted[j]; j++)
	{
		if (_strcmp(comodo, builted[j]) == 0)
			return (1);
	}
	return (0);
}

void smhandbuilted(char **comodo, char **argv, int *stato, int m)
{
	(void) argv;
	(void) m;

	if (_strcmp(comodo[0], "exit") == 0)
		exit_shell(comodo, stato);

	else if (_strcmp(comodo[0], "env") == 0)
		printenv(comodo, stato);
}

void exit_shell(char **comodo, int *stato)
{
	int j;

	for (j = 0; comodo[j]; j++)
		free(comodo[j]), comodo[j] = NULL;
	free(comodo), comodo = NULL;
	exit(*stato);
}

void printenv(char **comodo, int *stato)
{
	int i, j;
	(void) stato;
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	for (j = 0; comodo[j]; j++)
		free(comodo[j]), comodo[j] = NULL;
	free(comodo), comodo = NULL;
	*stato = 0;
}
