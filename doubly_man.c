#include "monty.h"

/**
 * print_dlistint - Prints all the elements of a doubly-linked lis\
t.
 * @h: Pointer to the head node of the list.
 *
 * This function prints all the elements (integer values) of a
 * doubly-linked list in forward order. The function traverses
 * the list using the given head node and prints each element's va\
lue.
 *
 * Return: The number of nodes (elements) in the list.
 */
void print_dlist(const stack_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
}

/**
 * add_dnode - Adds a new node at the beginning of a dlistint_t\
 list.
 * @head: A triple pointer to the head node of the list.
 * @n: The integer data to be added to the new node.
 *
 * This function creates a new node with the provided integer data\
 and adds
 * it to the beginning of the given dlistint_t doubly-linked list.\
 The head
 * pointer is updated to point to the new node, and the neighborin\
g nodes'
 * pointers are adjusted accordingly.
 *
 * Return: A pointer to the newly added node, or NULL on failure.
 */
stack_t *add_dnode(stack_t **head, const int n)
{
    stack_t *new_node;

	if (head == NULL)
	{
		return (NULL);
	}

	/* Create new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;

	/* Connect new node to existing nodes */
	new_node->prev = NULL; /* There's no prev node since it's now \
the first */
	new_node->next = *head; /* The next ptr become the ptr to the \
head node */

	/* Update pointer of neighbouring nodes */
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;

	return (new_node);
}

/* /\** */
/*  * get_dnodeint_at_index - Returns the nth node of a dlistint_t li\ */
/* nked list. */
/*  * @head: Pointer to the head of the list. */
/*  * @index: Index of the node, starting from 0. */
/*  * */
/*  * Return: Pointer to the nth node, or NULL if the node does not e\ */
/* xist. */
/*  *\/ */
/* stack_t *get_dnodeint_at_index(stack_t *head, unsigned int i\ */
/* ndex) */
/* { */
/* 	unsigned int count = 0; */
/* 	dlistint_t *current = head; */

/* 	while (current != NULL) */
/* 	{ */
/* 		if (count == index) */
/* 			return (current); */

/* 		current = current->next; */
/* 		count++; */
/* 	} */

/* 	return (NULL); */
/* } */

/* /\** */
/*  * sum_dlistint - Returns the sum of all data (n) in a dlistint_t \ */
/* linked list. */
/*  * @head: Pointer to the head of the list. */
/*  * */
/*  * Return: Sum of all data values, or 0 if the list is empty. */
/*  *\/ */
/* int add_dlist(stack_t *head) */
/* { */
/* 	int sum = 0; */
/* 	stack_t *current = head; */

/* 	while (current != NULL) */
/* 	{ */
/* 		sum += current->n; */
/* 		current = current->next; */
/* 	} */

/* 	return (sum); */
/* } */

/**
 * delete_dnodeint_at_index - Deletes the node at a given index.
 * @head: Pointer to a pointer to the head of the list.
 * @index: Index of the node to be deleted. Index starts at 0.
 *
 * Return: 1 if succeeded, -1 if failed.
 */
/* int delete_dnodeint_at_index(dlistint_t **head, unsigned int index\ */
/* ) */
/* { */
/* 	unsigned int count = 0; */
/* 	dlistint_t *current = *head; */

/* 	if (head == NULL || *head == NULL) */
/* 		return (-1); */

/* 	if (index == 0) */
/* 	{ */
/* 		*head = current->next; */
/* 		if (current->next != NULL) */
/* 			current->next->prev = NULL; */
/* 		free(current); */
/* 		return (1); */
/* 	} */

/* 	while (current != NULL) */
/* 	{ */
/* 		if (count == index) */
/* 		{ */
/* 			if (current->next != NULL) */
/* 				current->next->prev = current->prev; */

/* 			if (current->prev != NULL) */
/* 				current->prev->next = current->next; */

/* 			free(current); */
/* 			return (1); */
/* 		} */

/* 		current = current->next; */
/* 		count++; */
/* 	} */

/* 	return (-1); */
/* } */
