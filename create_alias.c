#include "main.h"

/**
 * search_alias - search if the alias is in the aliases list
 * @head: The head of the linked list that needs to be freed
 * @alias: The alias to find
 *
 * Return: If the alias is found - pointer to the alias
 *	   otherwise - NULL
 */
alias_t *search_alias(alias_t **head, char *alias)
{
	while (*head)
	{
		if (_strcmp((*head)->name, alias) == 0)
			return (*head);

		*head = (*head)->next;
	}

	return (NULL);
}

/**
 * create_alias - Add the new alias to the aliases linked list
 * @head: The head of the linked list that needs to be freed
 * @alias: The alias to add
 *
 * Return: void
 */
void create_alias(alias_t **head, char *alias)
{
	alias_t *alias_found;
	char **name_val_arr = split_string(alias, "=");

	alias_found = search_alias(head, name_val_arr[0]);

	if (alias_found)
	{
		free(alias_found->value);
		alias_found->value = _strdup(name_val_arr[1]);
	}
	else
	{
		printf("before %p\n", (void *) head);
		add_alias_end(head, name_val_arr[0], name_val_arr[1]);
		printf("after %p\n", (void *) head);
	}
	clean(name_val_arr);
}
