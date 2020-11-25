#include "shell.h"
/**
*p_prompt - print the prompt
*Return: 0 on succes 1 if failed
*/
int p_prompt(void)
{
	ssize_t w = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		w = write(1, "$ ", 2);
		if (w == -1)
			return (1);
	}
	return (0);
}
/**
*_puts - print a string
*@s: string to print
*/
void _puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		write(1, &s[i], 1);
	write(1, "\n", 1);
}
