#include "shell.h"
/**
*make_token - transform the string to tokens
*@buff: the string transformed
*Return: pointer to array of strings
*/
char **make_token(char *buff)
{
	char *token = NULL;
	int i = 0, words = 0;
	char **input = NULL;

	words = number_str(buff);
	if (!words)
		return (NULL);
	input = malloc((words + 1) * sizeof(char *));
	if (input == NULL)
	{
		perror("Allocation Error");
		exit(1);
	}
	token = strtok(buff, DELIM);
	while (token != NULL)
	{
		input[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	input[i] = NULL;
	return (input);
}
