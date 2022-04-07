#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

void execarg(char **args);
char **stringtok(char *str_line, const char *delimitator);
char *_which(char **args);
char *iscommand(char **args);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_getenv(char* str);
void printenv(void);
extern char **environ;
void ctrlC(int sig_num);
int breakline(char *str_line);

#endif
