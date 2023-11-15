#include "main.h"
/**
 * smexec - This is our executive script
 * @cmd: The result of smtok
 * @argv: An array[string] of the arguments passed to my program
 * Return: The status code of execution
 */
int smexec(char **cmd, char **argv)
{
	pid_t SON;
	int stat, j;

	SON = fork();
	if (SON == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			for (j = 0; cmd[j]; j++)
				free(cmd[j]), cmd[j] = NULL;
			free(cmd), cmd = NULL;
			exit(100);
		}
	}
	else
	{
		waitpid(SON, &stat, 0);
		for (j = 0; cmd[j]; j++)
			free(cmd[j]), cmd[j] = NULL;
		free(cmd), cmd = NULL;
	}
	return (WEXITSTATUS(stat));
}
