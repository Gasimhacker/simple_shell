#include "main.h"

/**
 * cmd_not_found_msg - Print an error if the command is not found
 * @shell_name: The name of the shell
 * @cmd: The command that we didn't find
 *
 * Return: void
 */
void cmd_not_found_msg(char *shell_name, char *cmd)
{
	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
}

/**
 * wrong_exit_code_msg - Print an error if the command is not found
 * @shell_name: The name of the shell
 * @exit_code: The wrong exit code
 *
 * Return: void
 */
void wrong_exit_code_msg(char *shell_name, char *exit_code)
{
	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": 1: exit: Illegal number: ", 27);
	write(STDERR_FILENO, exit_code, _strlen(exit_code));
	write(STDERR_FILENO, "\n", 1);
}
