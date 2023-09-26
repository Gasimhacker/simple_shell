#include "main2.h"

/**
 * _getlines - Super simple shell
 * @commands: The list were commands will be stored
 * @lines_count: An integer pointer to the number of lines/commands
 * Return: Always number of commands
 */
int _getlines(char **commands)
{
    char page[MAX_LINE_LENGTH];
    ssize_t bytes_read;
    char *trimmed_line, *end, *line;
    char ch;
    int j = 0, lines_count = 0, i;

    line = (char *)malloc(MAX_LINE_LENGTH * sizeof(page));
    bytes_read = read(STDIN_FILENO, page, sizeof(page));
    if (bytes_read <= 0)
		exit(1);
    page[bytes_read] = '\0';

    for (i = 0; i < bytes_read; i++)
    {
        ch = page[i];
        if (ch == '\n')
        {
            line[j] = '\0';
            j = 0;
            trimmed_line = line;
            while (*trimmed_line && (*trimmed_line == ' ' || *trimmed_line == '\t'))
                trimmed_line++;

            end = trimmed_line + strlen(trimmed_line) - 1;
            while (end > trimmed_line && (*end == ' ' || *end == '\t'))
                end--;
            *(end + 1) = '\0';
            if (strlen(trimmed_line) == 0)
                continue;
            commands[lines_count] = strdup(trimmed_line);
            (lines_count)++;
        }
        else
            line[j++] = ch;
    }
    free(line);
    return lines_count;
}
