#include "main.h"

#define MAX_LINE_LENGTH 100

/**
 * _getlines - Super simple shell
 * @commands: The list were commands will be stored
 *
 * Return: On success - number of commands
 *	   On error - "-1"
 */
int _getlines(char **commands)
{
	char *line, page[MAX_LINE_LENGTH], ch, qoute;
	ssize_t bytes_read;
	int j = 0, cmd_count = 0, i = 0;

	line = malloc(MAX_LINE_LENGTH * sizeof(page));
	if (line == NULL)
		return (-1);
	bytes_read = read(STDIN_FILENO, page, sizeof(page));
	if (bytes_read <= 0)
		return (-1);
	page[bytes_read] = '\0';
	while (i < bytes_read)
	{
		ch = page[i++];
		if (ch == '\"' || ch == '\'')
		{
			line[j++] = ch;
			qoute = ch;
			do {
				ch = page[i++];
				line[j++] = ch;
			} while (ch != qoute);
		}
		else if (ch == '\n')
		{
			line[j++] = '\0';
			commands[cmd_count] = _strdup(line);
			j = 0;
			(cmd_count)++;
		}
		else
			line[j++] = ch;
	}
	if (cmd_count == 0)
	{
		commands[cmd_count] = _strdup(line);
		cmd_count++;
	}
	free(line);
	return (cmd_count);
}
