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
	/* printf("-- ln: %u -- We are pushing stuffs\n", line_number); */

	int i;
	char **oag;
	int num;

	oag = monty_data.opcode_and_arg;

	if (oag[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if arg is a valid integer */
	for (i = 0; oag[1][i] != '\0'; i++)
	{
		if (!isdigit(oag[1][i]) && (oag[1][i] != '-'))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	/* Convert the argument to an integer using atoi */
	num = atoi(oag[1]);

	if (monty_data.mode == STACK)
		/* Add new node to the stack */
		add_dnode(container, num);
	else
		/* Add new node to the queue */
		add_dnode_end(container, num);
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

	print_dlist(*container);
}

/**
 * pint - print the value at the top of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void pint(stack_t **container, unsigned int line_number)
{
	if (*container == NULL)
	{
		/* Stack is empty */
		fprintf(stderr, "L%u: can't pint an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*container)->n);
}

/**
 * pop - delete the value at the top of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void pop(stack_t **container, unsigned int line_number)
{
	stack_t *temp;

	if (*container == NULL)
	{
		/* Stack is empty */
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *container;
	*container = temp->prev;

	if (*container)
		/* Update the top node's next pointer */
		(*container)->next = NULL;

	free(temp);
}

/**
 * swap - swap the top two elements of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void swap(stack_t **container, unsigned int line_number)
{
	stack_t *top, *second; /* Temp positions for top and 2top */

	if ((*container)->prev || *container == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *container;
	second = temp->prev;

	top-prev = second-prev;
	if (second->prev)
		second->prev-> = top;

	second->prev = top->next;
	if (top->next)
		top->next->prev = second;

	top->next = second;
	second->prev = top;

	*container = second; /* Container ponts to new top node */
}

/**
 * add - add the top two elements of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void add(stack_t **container, unsigned int line_number)
{
	stack_t *result;

	if ((*container)->prev || *container == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

	result = (*container)->n + (*contianer)->prev->n;

	/* Remove the top node */
	*container = (*container)->prev;

	/* Update the new top node's value with the result */
	(*container)->n = result;

	/* Free the memory of the node that was removed */
	free((*container)->next);

	/* Set the next pointer of the new top node to NULL */
	(*container)->next = NULL;
}

/**
 * nop - Do nothing.
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void nop(stack_t **container, unsigned int line_number)
{
	(void)container; /* Supress unused variable warning */
	(void)line_number;
}

/**
 * sub - sub the top element from the 2top element of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void sub(stack_t **container, unsigned int line_number)
{
    stack_t *temp;

    if ((*container)->prev || *container == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*container)->prev;
	temp->n -= (*container)->n;

    /* Remove the top node */
    *container = temp;

    /* Free the memory of the node that was removed */
    free(temp->next);

    /* Set the next pointer of the new top node to NULL */
    temp->next = NULL;
}

/**
 * div - divide the 2top element by the top element of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void div(stack_t **container, unsigned int line_number)
{
    stack_t *temp;
	int result;

    if ((*container)->prev || *container == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

	if ((*container)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

    temp = (*contianer)->prev;
	temp->n /= (*container)->n;

	/* Remove the top node */
	*container = temp;

    /* Free the memory of the node that was removed */
    free(temp->next);

    /* Set the next pointer of the new top node to NULL */
    temp->next = NULL;
}

/**
 * mul - multiply the 2top element with the top element of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void mul(stack_t **container, unsigned int line_number)
{
    stack_t *temp;

    if ((*container)->prev || *container == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*contianer)->prev;
	temp->n *= (*container)->n;

    free(*container);
	*container = temp;
}

/**
 * mod - computes the remainder of "2top/top".
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void div(stack_t **container, unsigned int line_number)
{
    stack_t *temp;
	int result;

    if ((*container)->prev || *container == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

	if ((*container)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

    temp = (*contianer)->prev;
	temp->n %= (*container)->n;

	/* Remove the top node */
	*container = temp;

    /* Free the memory of the node that was removed */
    free(temp->next);

    /* Set the next pointer of the new top node to NULL */
    temp->next = NULL;
}

/**
 * pchar - print the char at the top of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void pchar(stack_t **container, unsigned int line_number)
{
    if (*container == NULL)
    {
        /* Stack is empty */
        fprintf(stderr, "L%u: can't pchar an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

	if ((*container)->n < 0 || (*container)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}

    putchar((*container)->n);
	putchar('\n');
}

/**
 * pstr - print the string at the top of the stack
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void pstr(stack_t **container, unsigned int line_number)
{
	stack_t *i;

    if (*container == NULL)
    {
        /* Stack is empty */
        printf("\n");
		return;
    }

	while (*container != NULL && (*container)->n != 0
							  && (*container)->n > 0
		   && (*container)->n <= 127)
	{
		putchar((*container)->n);
		*container = *container->prev;
	}

	putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void rotl(stack_t **container, unsigned int line_number)
{
	stack_t *temp_h;

	/* Initialize */
	temp_h = *container;

	if ((temp_h)->prev == NULL || *temp_h == NULL)
	{
		return;
	}

	/* Traverse to the second element */
	while (temp_h->prev != NULL)
	{
		temp_h = temp_h->prev;
	}

	/* Adjust the pointers */
	temp_h->prev = *container;
	*container = (*container)->prev;
	(*container)->prev = NULL;
}


/**
 * rotr - rotates the stack to the bottom
 * @container: head pointer to doubly linked list (stack)
 * @line_number: current line number of execution
 *
 * Return: nothing
 */
void rotr(stack_t **container, unsigned int line_number)
{
    stack_t *temp, new_top;

    /* Initialize */
    temp = *container;
	new_top = temp;

    if ((temp)->prev == NULL || temp == NULL)
    {
        return;
    }

    /* Traverse to the second element */
    while (temp->prev != NULL)
    {
		new_top = temp;
        temp = temp->prev;
    }

    /* Adjust the pointers */
    (*container)->prev = new_top->prev;
	temp->prev = *container;
	new_top->prev = NULL;
	*container = new_top;
}

void stack(stack_t **container, unsigned int line_number)
{
	for (monty_data.mode == STACK)
		/* Add new node to the stack */
		add_dnode(container, num);
}

void queue(stack_t **container, unsigned int line_number)
{
	for (monty_data.mode == QUEUE)
	{
		/* Add new node to the queue */
		add_dnode_end(container, num);
	}
}
