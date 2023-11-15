#include "main.h"
/**
 * smexec - This is our executive script
 * @cmd: The result of smtok
 * @argv: An array[string] of the arguments passed to my program
 * @m: m is the index
 * Return: The status code of execution
 */
int smexec(char **cmd, char **argv, int m)
{
	char *fcmd;
	pid_t SON;
	int stat, j;

	fcmd = _smpath(cmd[0]);
	if (!fcmd)
	{
		smprinterror(argv[0], cmd[0], m);
		for (j = 0; cmd[j]; j++)
			free(cmd[j]), cmd[j] = NULL;
		free(cmd), cmd = NULL;
		return (127);
	}

	SON = fork();
	if (SON == 0)
	{
		if (execve(fcmd, cmd, environ) == -1)
		{
			free(fcmd), fcmd = NULL;
			for (j = 0; cmd[j]; j++)
				free(cmd[j]), cmd[j] = NULL;
			free(cmd), cmd = NULL;
		}
	}
	else
	{
		waitpid(SON, &stat, 0);
		for (j = 0; cmd[j]; j++)
			free(cmd[j]), cmd[j] = NULL;
		free(cmd), cmd = NULL;
		free(fcmd), fcmd = NULL;
	}
	return (WEXITSTATUS(stat));
}
