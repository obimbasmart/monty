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
	printf("-- ln: %u -- We are pushing stuffs\n", line_number);
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
}

