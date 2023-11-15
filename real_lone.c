#include "main.h"

/**
 * real_lone - This is my reading line fct
 * Return: The status code of the last execution
 */

char *real_lone(void)
{
	char *ln = NULL;
	size_t len = 0;
	ssize_t m;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	m = getline(&ln, &len, stdin);

	if (m == -1)
	{
		free(ln);
		return (NULL);
	}
	return (ln);
}

