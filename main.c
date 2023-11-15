#include "main.h"
#include <stdio.h>

/**
 * main - This is my simple shell main.c
 * @argc: The number of arguments passed to my program
 * @argv: An array[string] of the arguments passed to my program
 * Return: The status code of the last execution
 */

int main(int argc, char **argv)
{
	char *lone = NULL;
	char **comodo = NULL;
	int stato = 0;
	(void) argc;

	while (1)
	{
		lone = real_lone();
		if (lone == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stato);
		}

		comodo = smtok(lone);
		if (!comodo)
			continue;

	stato = smexec(comodo, argv);



	/**
		* for (j = 0; comodo[j]; j++)
			free(comodo[j]), comodo[j] = NULL;

		free(comodo), comodo = NULL;
	*/
	}
}
