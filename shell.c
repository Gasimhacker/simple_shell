#include "main.h"

/**
 * main - Super simple shell
 *
 * Return: Always 0.
 */
int main(int __attribute__((unused))argc, char **argv)
{
	alias_t *head = NULL;

	copy_to_heap();

	if (!isatty(STDIN_FILENO))
		run_non_interactive(&head, argv[0]);
	else
		run_interactive(&head, argv[0]);

	clean(environ);

	return (0);
}
