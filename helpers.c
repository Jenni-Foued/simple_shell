#include "shell.h"
/**
*_memset - set the memory with a constant byte
*@s: array to fill
*@c: character to fill with
*@bytes: number of bytes to fill
*Return: new array
*/
char *_memset(char *s, char c, unsigned int bytes)
{
	unsigned int i;

	for (i = 0; i < bytes; i++)
		s[i] = c;
	return (s);
}
/**
*_getenv - get the PATH
*@member: PATH string
*Return: pointer to member if found
*/
char *_getenv(const char *member)
{
	int i, r;

	for (i = 0; environ[i]; i++)
	{
		r = _strcmp_path(member, environ[i]);
		if (r == 0)
			return (environ[i]);
	}
	return (NULL);
}
/**
*_strcmp - compare 2 strings
*@s1: first string
*@s2: second string
*Return: integer
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}
/**
*_environ - print the environ
*Return: 0 on success
*/
int _environ(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}
