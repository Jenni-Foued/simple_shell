#include "shell.h"
/**
*number_str - number of flags
*@s: string to search in
*Return: number of flags
*/
int number_str(char *s)
{
	int i, flag = 1, words = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ' && flag == 1)
		{
			words += 1;
			flag = 0;
		}
		if (s[i + 1] == ' ')
			flag = 1;
	}
	return (words);
}
/**
*_strdup - Duplicated strings
*@s: string to make 2
*Return: pointer to s2
*/
char *_strdup(char *s)
{
	int i;
	char *d = NULL;

	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		i++;
	}
	d = malloc((i + 1) * sizeof(char));
	if (d == NULL)
	{
		perror("Allocation Error");
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
/**
* _strlen - length of a string.
* @s: A pointer to the characters string.
* Return: The length of the string.
*/
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}
/**
*_strcat - concatenates two strings
*@dest: Destination
*@src: source
*Return: char (source in the end of destination)
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i] != '\0')
		i++;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i + 1] = '\0';
	return (dest);
}
/**
*_strcmp_path - compare PATH and environ
*@PATH: My PATH
*@environ: Environ
*Return: 0 if yes  1 if no
*/
int _strcmp_path(const char *PATH, const char *environ)
{
	int i;

	for (i = 0; environ[i] != '='; i++)
	{
		if (PATH[i] != environ[i])
			return (1);
	}
	return (0);
}
