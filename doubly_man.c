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


/**
 * add_dnode_end - Adds a new node at the end of a dlistint_t list\
.
 * @head: A triple pointer to the head node of the list.
 * @n: The integer data to be added to the new node.
 *
 * This function creates a new node with the provided integer data
 and adds
 * it to the beginning of the given dlistint_t doubly-linked list.
 The head
 * pointer is updated to point to the new node, and the neighborin
g nodes'
 * pointers are adjusted accordingly.
 *
 * Return: A pointer to the newly added node, or NULL on failure.
 */
stack_t *add_dnode_end(stack_t **head, const int n)
{
    stack_t *new_node, *current;

    /* Create new node */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
        return (NULL);  /* Check for memory allocation failure */

    new_node->n = n;  /* Assign the provided data to the new node */
    new_node->next = NULL; /* The new node will be the last node */

    if (*head == NULL)
    {
        /*If list is empty, new node becomes the head */
        new_node->prev = NULL;
        *head = new_node;
        return (new_node);
    }
    /* Traverse to the last node */
    current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    /* Connect new node to existing nodes */
    new_node->prev = current;  /* There's no previous node */
    current->next = new_node;

    return (new_node);   /* Return the new node */
}

/**
 * pop_end - delete the value at the end of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void pop_end(stack_t **container, unsigned int line_number)
{
    stack_t *temp;

    if (*container == NULL)
    {
        /* Stack is empty */
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *container;

    if (temp->prev)
        /* Update the previous node's next pointer */
        temp->prev->next = NULL;

	*container = temp->prev;

	free(temp);
}
