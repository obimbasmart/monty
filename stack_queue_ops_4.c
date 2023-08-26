#include "monty.h"

/**
 * rotr - otates the stack to the bottom
 * the last element of the stack becomes the top element
 *
 * @container: head pointer to stack/queue
 * @line_number: current line number in execution
 *
 * Return: nothing
 */
void rotr(stack_t **container, unsigned int line_number)
{
	stack_t *head_copy, *last_node;

	(void)line_number; /* unused param */
	if (is_less_than_two(container))
		return;

	last_node = head_copy = *container;

	/* get the last node */
	while (last_node->next)
		last_node = last_node->next;

	(*container)->prev = last_node;
	last_node->next = (*container)->next;
	last_node->prev->next = NULL;
	last_node->prev = NULL;

	*container = last_node;

}



