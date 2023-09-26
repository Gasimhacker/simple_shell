#include "main.h"

/**
 * check_separator - Searh a buffer for some seprator 
 * @buff: Buffer to be searched for a seprator
 * Return: Returns the seperator
 */
int check_separator(char *buff)
{
    char **commands;
    if (_strstr(buff,";"))
    {
        commands = split_string(buff,";");
        handle_colon(commands);
    }
    else if (_strstr(buff,"&&"))
    {
        commands = split_string(buff,"&&");
        handle_anding(commands);
    }
    else if (_strstr(buff,"||"))
    {
        commands = split_string(buff,"||");
        handle_oring(commands);
    }
    else
        return(0);
    return (1);
}

/**
 * handle_anding - handles and Executes the command seperated by '&&'
 * @commands: List of command to be separated
 * Return: void
 */
void handle_anding(char **commands)
{
    int *last_exit_code;
    int i = 0;

    search_execute(commands[i++]);
    while (commands[i])
    {
        last_exit_code = get_exit_status();
        if (*last_exit_code == EXIT_SUCCESS)
            search_execute(commands[i++]);
        else
            break;
    }
}

/**
 * handle_oring - handles and Executes the command seperated by '||'
 * @commands: List of command to be separated
 * Return: void
 */
void handle_oring(char **commands)
{
    int *last_exit_code ;
    int i = 0;
    search_execute(commands[i++]);
    while (commands[i])
    {
        last_exit_code = get_exit_status();
        if (*last_exit_code == EXIT_SUCCESS)
            break;
        else
            search_execute(commands[i++]);
    }
}

/**
 * handle_colon - handles and Executes the command seperated by ';'
 * @commands: List of command to be separated
 * Return: void
 */
void handle_colon(char **commands)
{
    int i = 0;
    while (commands[i])
        search_execute(commands[i++]);
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
			{
				return (haystack);
			}
			index++;
		}
		haystack++;

	}

	return (0);
}
