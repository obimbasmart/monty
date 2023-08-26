#include "monty.h"

/**
 * push - append item to stack (or queue)
 * @container: head pointer to doubly linked list
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void push(stack_t **container, unsigned int line_number)
{
	char *endptr;
	long int n;

	/* check if argument is passd to push */
	if (!monty_data.opcode_and_arg[1])
		error_handler(line_number, "usage: push integer", NULL, NULL);

	n = strtol(monty_data.opcode_and_arg[1], &endptr, 10);

	/* check if argument is a valid  integer */
	if (*endptr != '\0' || !monty_data.opcode_and_arg[1])
		error_handler(line_number, "usage: push integer", NULL, NULL);

	/* if insertion is for QUEUE */
	if (!(*container) || monty_data.mode == QUEUE)
	{
		(add_dnodeint_end(container, n));
		return;
	}

	/* insertion for STACK */
	if (monty_data.mode == STACK)
		(add_dnodeint(container, n));


}

/**
 * pall - print the container (stack or queue)
 * @container: head pointer to doubly linked list
 * @line_number: the current line number executing
 *
 * Return: nothing
 */
void pall(stack_t **container, unsigned int line_number)
{
	size_t index;
	stack_t *container_copy = *container;

	(void)line_number; /* unused variable */

	if (!container)
		return;

	index = 0;
	while (container_copy)
	{
		printf("%d\n", container_copy->n);
		container_copy = container_copy->next;
		index++;
	}

	container_copy = *container;
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @container: head pointer to doubly linked list
 * @line_number: current line number in execution
 *
 * Return: nothing
 */
void pint(stack_t **container, unsigned int line_number)
{
	if (is_empty(container))
		error_handler(line_number, "can't pint, stack empty", NULL, NULL);

	printf("%d\n", (*container)->n);
}

/**
 * queue - change the mode of the container to queue
 * @container: the head pointer of the doubly linked list
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void queue(stack_t **container, unsigned int line_number)
{
	(void)container; /* unused variable */
	(void)line_number; /* unused variable */

	monty_data.mode = QUEUE;
}

/**
 * stack - change the mode of the container to stack
 * @container: the head pointer of the doubly linked list
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void stack(stack_t **container, unsigned int line_number)
{
	(void)container; /* unused variable */
	(void)line_number; /* unused variable */
	monty_data.mode = STACK;
}

