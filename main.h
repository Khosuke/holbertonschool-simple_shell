#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

char **split_string(char *buffer, char *separator);
void free_array(char **array);
char *_getenv(const char *name);
char *_which(char *commandName);

#endif
