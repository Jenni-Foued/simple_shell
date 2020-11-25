#include "shell.h"
/**
*concatation - the commands get to the PATH
*@tmp: static array to store the new string
*@input: the user command
*@token: PATH token
*Return: the new PATH with user command in it
*/
char *concatation(char *tmp, char **input, char *token)
{
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(token) + _strlen(input[0]) + 2;
	_strcat(tmp, token);
	_strcat(tmp, "/");
	_strcat(tmp, input[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}
