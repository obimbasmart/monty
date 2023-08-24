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
	/* printf("-- ln: %u -- We are pushing stuffs\n", line_number); */

	int i;
	char **oag;
	int num;

	oag = monty_data.opcode_and_arg;

	if (oag[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if arg is a valid integer */
	for (i = 0; oag[1][i] != '\0'; i++)
	{
		if (!isdigit(oag[1][i]) && (oag[1][i] != '-'))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	/* Convert the argument to an integer using atoi */
	num = atoi(oag[1]);

	if (monty_data.mode == STACK)
		/* Add new node to the stack */
		add_dnode(container, num);
	else
		/* Add new node to the queue */
		add_dnode_end(container, num);
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
	printf("-- ln: %u -- We're printing stuffs\n", line_number);

	print_dlist(*container);
}

/**
 * pint - print the value at the top of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void pint(stack_t **container, unsigned int line_number)
{
	if (*container == NULL)
	{
		/* Stack is empty */
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*container)->n);
}

void pop(stack_t **container, unsigned int line_number)
{
	stack_t *temp;

	if (*container == NULL)
	{
		/* Stack is empty */
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *container;
	*container = temp->prev;

	if (*container)
	{
		/* Update the top node's next pointer */
		(*container)->next = NULL;
	}
}
