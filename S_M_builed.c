#include "main.h"

/**
 * _smbuilted - This is our executive script
 * @comodo: The result of smtok
 * Return: the index
 */

int _smbuilted(char *comodo)
{
	char *builted[] = {"exit", "env", "setenv", "cd", NULL};
	int j;

	for (j = 0; builted[j]; j++)
	{
		if (_strcmp(comodo, builted[j]) == 0)
			return (1);
	}
	return (0);
}

/**
 * smhandbuilted - This is our executive script
 * @comodo: m is the index
 * @argv: The result of smtok
 * @stato: The result of smtok
 * @m: The result of smtok
 */

void smhandbuilted(char **comodo, char **argv, int *stato, int m)
{
	if (_strcmp(comodo[0], "exit") == 0)
		exit_shell(comodo, argv, stato, m);

	else if (_strcmp(comodo[0], "env") == 0)
		printenv(comodo, stato);
}

/**
 * exit_shell - This is our executive script
 * @comodo: m is the index
 * @argv: The result of smtok
 * @stato: The result of smtok
 * @m: The result of smtok
 */
void exit_shell(char **comodo, char **argv, int *stato, int m)
{
	int j;
	int exval = (*stato);
	char *idu, MSG[] = ": exit : Illegal number: ";

	if (comodo[1])
	{
		if (_is_pos(comodo[1]))
		{
			exval = _atoi(comodo[1]);
		}
		else
		{
			idu  = _itoa(m);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idu, _strlen(idu));
			write(STDERR_FILENO, MSG, _strlen(MSG));
			write(STDERR_FILENO, comodo[1], _strlen(comodo[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idu);
			for (j = 0; comodo[j]; j++)
				free(comodo[j]), comodo[j] = NULL;
			free(comodo), comodo = NULL;
			(*stato) = 2;
			return;
		}

	}
	for (j = 0; comodo[j]; j++)
		free(comodo[j]), comodo[j] = NULL;
	free(comodo), comodo = NULL;
	exit(exval);
}
/**
 * printenv - This is our executive script
 * @comodo: m is the index
 * @stato: The result of smtok
 */
void printenv(char **comodo, int *stato)
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	for (j = 0; comodo[j]; j++)
		free(comodo[j]), comodo[j] = NULL;
	free(comodo), comodo = NULL;
	(*stato) = 0;
}
