#include "main.h"


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
	
	return(_strdup(buff));

}

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
