#include "shell.h"
/**
*path_members - number of PATH members
*@s: string to count
*Return: Path elements
*/
int path_members(char *s)
{
	int i;
	int flag = 1, words = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ':' && flag == 1)
		{
			words += 1;
			flag = 0;
		}
		if (s[i + 1] == ':')
			flag = 1;
	}
	return (words);
}
