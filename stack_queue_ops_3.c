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
	size_t stack_length, index;
	char *str;
	stack_t *container_copy;

	(void)line_number; /* unused variable */
	if (is_empty(container))
	{
		printf("\n");
		return;
	}

	stack_length = get_container_size(*container);
	str = malloc(sizeof(char) * (stack_length + 1));

	index = 0;
	container_copy = *container;
	while (*container)
	{
		if (!(is_ascii((*container)->n)) || (*container)->n == 0)
			break;

		str[index] = (char)(*container)->n;
		*container = (*container)->next;
		index++;
	}

	*container = container_copy;
	str[index] = '\n';
	printf("%s", str);
}

