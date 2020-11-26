#ifndef HOLBERTON_H
#define HOLBERTON_H

#define DELIM " \n"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;
void signal_to_handel(int sig);
int builtins(char **input, char *buff, int exit);
char *concatation(char *tmp, char **input, char *token);
int execute(char **input, char *buff, char *fpathbuff);
char *fpath(char **input, char *PATH, char *c);
int _environ(void);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *member);
char *_memset(char *s, char c, unsigned int bytes);
char **make_token(char *buff);
int path_members(char *s);
int p_prompt(void);
void _puts(char *s);
char *readline(void);
int number_str(char *s);
char *_strdup(char *s);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
int _strcmp_path(const char *PATH, const char *environ);
int _cd(char **input);

#endif
