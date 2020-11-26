#include "shell.h"
/**
*execute - executing the command
*@input: array of command
*@buff: string of the command
*@fpathbuff: string of the path
*Return: 0 on succes
*/
int execute(char **input, char *buff, char *fpathbuff)
{
	int i, stat, ex, exitv = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		ex = execve(fpathbuff, input, environ);
		if (ex == -1)
		{
			perror(input[0]);
			for (i = 0; input[i]; i++)
				free(input[i]);
			free(input);
			free(buff);
			exit(127);
		}
	}
	wait(&stat);
	if (WIFEXITED(stat))
		exitv = WEXITSTATUS(stat);
	for (i = 0; input[i]; i++)
		free(input[i]);
	free(input);
	free(buff);
	return (exitv);
}
/**
 * signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n$ ", 3);
	}
}
