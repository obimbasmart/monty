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

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @container: head pointer to stack/queue
 * @line_number: current line number in execution
 *
 * Return: nothing
 */
void pchar(stack_t **container, unsigned int line_number)
{
	if (is_empty(container))
		error_handler(line_number, "can't pchar, stack empty", NULL, NULL);

	if (!((*container)->n > 31 && (*container)->n < 128))
		error_handler(line_number, "can't pchar, value out of range", NULL, NULL);

	printf("%c\n", (*container)->n);
}


/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line. The integer stored in each element
 * of the stack is treated as the ascii value of
 * the character to be printed
 *
 * @container: head pointer to stack/queue
 * @line_number: current line number in execution
 *
 * Return: nothing
 */
void pstr(stack_t **container, unsigned int line_number)
{
	stack_t *container_copy;

	(void)line_number; /* unused variable */
	if (is_empty(container))
	{
		printf("\n");
		return;
	}

	container_copy = *container;
	while (*container)
	{
		if (!(is_ascii((*container)->n)) || (*container)->n == 0)
			break;

		printf("%c", (*container)->n);
		*container = (*container)->next;
	}

	*container = container_copy;
	printf("%c", '\n');
}


/**
 * rotl - rotates the stack to the top - The top element of the stack becomes
 * the last one, and the second top element of the stack becomes the first one
 *
 * @container: head pointer to stack/queue
 * @line_number: current line number in execution
 *
 * Return: nothing
 */
void rotl(stack_t **container, unsigned int line_number)
{
	stack_t *next_node, *last_node;

	(void)line_number; /* unused param */
	if (is_less_than_two(container))
		return;

	last_node = *container;
	next_node = (*container)->next;

	/* get the last node */
	while (last_node->next)
		last_node = last_node->next;

	(*container)->prev = last_node;
	last_node->next = *container;
	(*container)->next->prev = NULL;
	(*container)->next = NULL;

	*container = next_node;

}


