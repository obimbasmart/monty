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
 * get_last_node - get the last node of a doubly linked list
 * @head: head pointer to list
 *
 * Return: last_node - stack_t *
 */
stack_t *get_last_node(stack_t **head)
{
	stack_t *head_copy, *last_node;

	if (is_empty(head))
		return (NULL);

	last_node = head_copy = *head;
	while (last_node->next)
		last_node = last_node->next;

	*head = head_copy;
	return (last_node);
}
