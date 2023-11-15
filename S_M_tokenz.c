#include "main.h"

/**
 * smtok - This is our tokenizer fonctions made by us line by line
 * @line: your inputs baby user
 * Return: The strings of input
 */

char **smtok(char *line)
{
	char *tok = NULL, *temp = NULL;
	char **cmd = NULL;
	int ct = 0, j = 0;

	if (!line)
		return (NULL);
	temp = _strdup(line);

	tok = strtok(temp, DLM);
	if (tok == NULL)
	{
		free(temp), temp = NULL;
		free(line), line = NULL;
		return (NULL);
	}


	while (tok)
	{
		ct++;
		tok = strtok(NULL, DLM);
	}
	free(temp), temp = NULL;

	cmd = malloc(sizeof(char *) * (ct + 1));
	if (!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}

	tok = strtok(line, DLM);

	while (tok)
	{
		cmd[j] = _strdup(tok);
		tok = strtok(NULL, DLM);
		j++;
	}
	free(line), line = NULL;
	cmd[j] = NULL;
	return (cmd);
}
