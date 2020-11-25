#include "shell.h"
/**
*main - our shell
*Return: 1 on fail 0 on success
*/
int main(void)
{
	char *fPATH = NULL, *c = NULL, *buff = NULL;
	char *PATH = NULL;
	char **input;
	int exit = 0;

	signal(SIGINT, SIG_IGN);
	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (1);
	do {
		input = NULL;
		p_prompt();
		buff = readline();
		if (*buff != '\0')
		{
			input = make_token(buff);
			if (input == NULL)
			{
				perror("Make Token Error");
				free(buff);
				continue;
			}
			fPATH = fpath(input, PATH, c);
			if (builtins(input, buff, exit) != 0)
				continue;
			exit = execute(input, buff, fPATH);
		}
		else
			free(buff);
	} while (1);
	return (0);
}
