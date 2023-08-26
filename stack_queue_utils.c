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
		error_handler(0, "Error: malloc failed", NULL, NULL);

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
		error_handler(0, "Error: malloc failed", NULL, NULL);

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

/**
 * is_empty - check if stack, or queue is empty
 * @head: head pointer to doubly linked list
 *
 * Return: 1 if empty, 0 if not
 */
int is_empty(stack_t **head)
{
	if (!head || !(*head))
		return (1);

	return (0);
}

/**
 * is_less_than_two - check if no. of nodes is less
 * than two elements
 * @head: head pointer to doubly linked list
 *
 * Return: 1 if less than two, 0 if more than 2
 */
int is_less_than_two(stack_t **head)
{
	if (!head || !(*head) || !((*head)->next))
		return (1);

	return (0);
}

