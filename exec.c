#include "main.h"

/**
 * execute - Execute the passed command
 * @args: The arguments passed to the command
 * @program_path: The path to the program to be executed
 *
 * Return: On success - 0
 *	   On error - 1
 */
int execute(char **args, char *program_path)
{
	int status, *exit_status = get_exit_status();
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(program_path, args, environ) == -1)
		{
			clean(args);
			free(program_path);
			exit(1);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status))
			*exit_status = WEXITSTATUS(status);

		free(program_path);
		clean(args);
	}
	return (*exit_status);
}
