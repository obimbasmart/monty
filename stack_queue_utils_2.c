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
