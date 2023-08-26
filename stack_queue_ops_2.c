#include "monty.h"

/**
 * pop - remove the element at the top of the stack/queue
 * @container: head pointer to stack,queue
 * @line_number: line number in execution
 *
 */
void pop(stack_t **container, unsigned int line_number)
{
	stack_t *next_head;

	if (is_empty(container))
		error_handler(line_number, "can't pop an empty stack", NULL, NULL);

	next_head = (*container)->next;
	free(*container);
	*container = next_head;
}

