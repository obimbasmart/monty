#include "monty.h"

/**
 * pop - remove the element at the top of the stack/queue
 * @container: head pointer to stack,queue
 * @line_number: line number in execution
 *
 * Return: nothing
 */
void pop(stack_t **container, unsigned int line_number)
{
	if (is_empty(container))
		error_handler(line_number, "can't pop an empty stack", NULL, NULL);

	delete_first_node(container);
}

/**
 * swap - swap the top two elements of a stack/queue
 * @container: head pointer to stack/queue
 * @line_number: current line number in execution
 *
 * Return: nothing
 */
void swap(stack_t **container, unsigned int line_number)
{
	stack_t *second_node;

	if (is_less_than_two(container))
		error_handler(line_number, "can't swap, stack too short", NULL, NULL);

	second_node = (*container)->next;
	(*container)->next = second_node->next;

	if (second_node->next)
		second_node->next->prev = *container;
	second_node->next = *container;
	second_node->prev = NULL;
	*container = second_node;
}


/**
 * add - add the top two elements of a stack/queue
 * @container: head pointer to stack/queue
 * @line_number: current line number in execution
 *
 * Return: nothing
 */
void add(stack_t **container, unsigned int line_number)
{
	int n;

	if (is_less_than_two(container))
		error_handler(line_number, "can't add, stack too short", NULL, NULL);

	n = (*container)->n + (*container)->next->n;
	delete_first_node(container);
	delete_first_node(container);
	add_dnodeint(container, n);
}

