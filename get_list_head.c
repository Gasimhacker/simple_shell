#include "main.h"

/**
 * get_head - Get the head of the aliases linked list
 *
 * Return: A pointer to the head of the linked list
 */
alias_t *get_head(void)
{
	static alias_t *head;

	return (head);
}
