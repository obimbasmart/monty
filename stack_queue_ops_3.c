#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @container: head pointer to stack/queue
 * @line_number: current line number in execution
 *
 * Return: nothing
 */
void mul(stack_t **container, unsigned int line_number)
{
	int n;

	if (is_less_than_two(container))
		error_handler(line_number, "can't mul, stack too short", NULL, NULL);

	n = (*container)->next->n * (*container)->n;
	delete_first_node(container);
	delete_first_node(container);
	add_dnodeint(container, n);
}


/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element
 * @container: head pointer to stack/queue
 * @line_number: current line number in execution
 *
 * Return: nothing
 */
void mod(stack_t **container, unsigned int line_number)
{
	int n;

	if (is_less_than_two(container))
		error_handler(line_number, "can't mod, stack too short", NULL, NULL);

	if ((*container)->n == 0)
		error_handler(line_number, "division by zero", NULL, NULL);
	n = (*container)->next->n % (*container)->n;
	delete_first_node(container);
	delete_first_node(container);
	add_dnodeint(container, n);
}

