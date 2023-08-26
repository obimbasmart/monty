#include "monty.h"

/**
 * delete_first_node - deletes the topmost node
 * @head: head to doubly linked list
 *
 * Return: nothing
 */
void delete_first_node(stack_t **head)
{
	stack_t *next_head = (*head)->next;

	free(*head);
	*head = next_head;
}

/**
 * is_noop_opcode - checks if an opcode is a 'no-operation' action
 * @opcode: opcode
 *
 * Return: 1 if opcode is a noop, else 0
 */
int is_noop_opcode(char *opcode)
{
	if (!opcode || opcode[0] == '#' ||
			strcmp(opcode, "nop") == 0)
		return (1);

	return (0);
}

/**
 * is_ascii - check if an int is in ascii table
 * @n: integer
 *
 * Return: 1 if in table, 0 if not
 */
int is_ascii(int n)
{
	if (n > 31 && n < 128)
		return (1);
	return (0);
}

/**
 * get_container_size - get the no. of items in stack/queue
 * @head: head pointer to stack/queue
 *
 * Return: integer
 */
size_t get_container_size(stack_t *head)
{
	size_t stack_len = 0;
	stack_t *head_copy = head;

	while (head)
	{
		stack_len++;
		head = head->next;
	}

	head = head_copy;
	return (stack_len);
}
