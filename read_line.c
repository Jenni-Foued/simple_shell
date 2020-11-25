#include "shell.h"
/**
*readline - read the line from stdin
*Return: pointer to the read line
*/
char *readline(void)
{
	ssize_t r = 0;
	size_t sl = 0;
	char *buff = NULL;
	int i = 0;

	r = getline(&buff, &sl, stdin);
	if (r == -1)
	{
		free(buff);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buff[r - 1] == '\n' || buff[r - 1] == '\t')
		buff[r - 1] = '\0';
	for (i = 0; buff[i]; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ')
		{
			buff[i] = '\0';
			break;
		}
	}
	return (buff);
}
