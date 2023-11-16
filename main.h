#ifndef MAIN_H
#define MAIN_H



#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 1024
#define DLM " \t\n"

extern char **environ;

char *real_lone(void);
char **smtok(char *line);
int smexec(char **cmd, char **argv, int m);
char *_smgetenv(char *varo);
char *_smpath(char *comodo);

void smprinterror(char *name, char *cmd, int m);
char *_itoa(int j);
void rev_str(char *st, int ln);

int _smbuilted(char *comodo);
void smhandbuilted(char **comodo, char **argv, int *stato, int m);
void exit_shell(char **comodo, int *stato);
void printenv(char **comodo, int *stato);


int _strlen(char *str);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);



#endif /* MAIN_H */
