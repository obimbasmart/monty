#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: head node of stack_t list
 * @n: data for new node
 *
 * Return: nothing
 */
void add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		error_handler("Error: malloc failed", NULL);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!(*head)) /* empty linked list */
	{
		*head = new_node;
		return;
	}

	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
}

/**
 * add_dnodeint_end - adds a new node at the beginning of a stack_t list.
 * @head: head node of stack_t list
 * @n: data for new node
 *
 * Return: nothing
 */
void add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *last_node;

	last_node = *head;
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		error_handler("Error: malloc failed", NULL);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!(*head)) /* empty list */
	{
		*head = new_node;
		return;
	}

	while (last_node->next)
		last_node = last_node->next;


	last_node->next = new_node;
	new_node->prev = last_node;

}

/**
 * free_container - function that frees a dlistint_t list.
 * @head: head node of dlistint_t list
 *
 * Return: Nothing
 */
void free_container(stack_t **head)
{
	stack_t *ptr_copy;

	if (!head)
		return;

	while (*head)
	{
		ptr_copy = (*head)->next;
		free(*head);
		*head = ptr_copy;
	}

	free(*head);
	head = NULL;
}

