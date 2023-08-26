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

