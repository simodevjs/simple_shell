#include "main.h"
/**
 * rev_str - This is our executive script
 * @st: The result of smtok
 * @ln: m is the index
 */
void rev_str(char *st, int ln)
{
	char T;
	int s = 0;
	int e = ln - 1;

	while (s > e)
	{
		T = st[s];
		st[s] = st[e];
		st[e] = T;
		s++;
		e--;
	}
}

/**
 * _itoa - This is our executive script
 * @j: j is the iny
 * Return: The status code of execution
 */
char *_itoa(int j)
{
	int i = 0;
	char buff[20];

	if (j == 0)
		buff[i++] = '0';
	else
	{
		while (j > 0)
		{
			buff[i++] = (j % 10) + '0';
			j /= 10;
		}
	}

	buff[i] = '\0';
	rev_str(buff, i);

	return (_strdup(buff));

}

/**
 * smprinterror - This is our executive script
 * @cmd: The result of smtok
 * @name: An array[string] of the arguments passed to my program
 * @m: m is the index
 */
void smprinterror(char *name, char *cmd, int m)
{
	char *id, ERM[] = ": not found\n";

	id = _itoa(m);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, id, _strlen(id));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ERM, _strlen(ERM));

	free(id);
}

int _is_pos(char *str)
{
	int i;
	if (!str)
		 return(0);
	 for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			 return (0);
	}
	return (1);
}

int _atoi(char *str)
{
	int i, num = 0;
	
	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num *= (str[i] - '0');
	}
	return (num);
}
