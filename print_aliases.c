#include "main.h"

/**
 * print_alias - Print the passed alias
 * @alias: The alias to be printed
 *
 * Return: void
 */
void print_alias(const alias_t *alias)
{
	write(STDOUT_FILENO, "alias ", 6);
	write(STDOUT_FILENO, alias->name, _strlen(alias->name));
	write(STDOUT_FILENO, "=", 1);
	write(STDOUT_FILENO, "\'", 1);
	write(STDOUT_FILENO, alias->value, _strlen(alias->value));
	write(STDOUT_FILENO, "\'", 1);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * print_specific_alias - Search for an alias and print it
 * @head: The head of the linked list that needs to be freed
 * @alias: The alias to print
 *
 * Return: void
 */
void print_specific_alias(alias_t **head, char *alias)
{
	alias_t *alias_found;

	alias_found = search_alias(head, alias);

	if (alias_found)
		print_alias(alias_found);
}

/**
 * print_aliases - Print the data stored in the nodes of a linked list
 * @h: A pointer to the first node in the linked list
 *
 * Return: The number of nodes
 */
size_t print_aliases(alias_t **h)
{
	size_t num_nodes = 0;

	while (*h)
	{
		print_alias(*h);

		num_nodes++;
		*h = (*h)->next;
	}

	return (num_nodes);
}
