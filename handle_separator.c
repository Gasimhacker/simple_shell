#include "main.h"

/**
 * check_separator - Searh a buffer for some seprator
 * @buff: Buffer to be searched for a seprator
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 *
 * Return: Returns the seperator
 */
int check_separator(char *buff, alias_t **head, char *shell_name)
{
	char **commands = NULL;

	if (_strstr(buff, ";"))
	{
		commands = split_string(buff, ";");
		handle_colon(commands, head, shell_name);
	}
	else if (_strstr(buff, "&&"))
	{
		commands = split_string(buff, "&&");
		handle_anding(commands, head, shell_name);
	}
	else if (_strstr(buff, "||"))
	{
		commands = split_string(buff, "||");
		handle_oring(commands, head, shell_name);
	}

	if (commands)
	{
		free(commands);
		return (1);
	}

	return (0);
}

/**
 * handle_anding - handles and Executes the command seperated by '&&'
 * @commands: List of command to be separated
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 *
 * Return: void
 */
void handle_anding(char **commands, alias_t **head, char *shell_name)
{
	int *last_exit_code, i = 0;

	search_execute(commands[i++], head, shell_name);
	while (commands[i])
	{
		last_exit_code = get_exit_status();
		if (*last_exit_code == EXIT_SUCCESS)
			search_execute(commands[i++], head, shell_name);
		else
			break;
	}
}

/**
 * handle_oring - handles and Executes the command seperated by '||'
 * @commands: List of command to be separated
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 *
 * Return: void
 */
void handle_oring(char **commands, alias_t **head, char *shell_name)
{
	int *last_exit_code, i = 0;

	search_execute(commands[i++], head, shell_name);
	while (commands[i])
	{
		last_exit_code = get_exit_status();
		if (*last_exit_code == EXIT_SUCCESS)
			break;
		search_execute(commands[i++], head, shell_name);
	}
}

/**
 * handle_colon - handles and Executes the command seperated by ';'
 * @commands: List of command to be separated
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 *
 * Return: void
 */
void handle_colon(char **commands, alias_t **head, char *shell_name)
{
	int i = 0;

	while (commands[i])
		search_execute(commands[i++], head, shell_name);
}

/**
 * _strstr - Locate a substring
 * @haystack: The string to be searched
 * @needle: The substring that should be located
 *
 * Return: A pointer to the beginning of the located
 *	   substring, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int index;

	if (*needle == 0)
	{
		return (haystack);
	}
	while (*haystack)
	{
		index = 0;

		while (*(haystack + index) == needle[index] && needle[index])
		{
			if (needle[index + 1] == '\0')
				return (haystack);
			index++;
		}
		haystack++;
	}

	return (0);
}
