#ifndef MONTY_H
#define MONTY_H

/* builtins libs */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define STACK 1
#define QUEUE 0
#define TOKEN_BUFFERSIZE 120
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct global_vars - serves as a container for all global variables
 * @mode: this is a flag, specifying the mode of the container (stack | queue)
 * @line_number: command line number being executed at any point in time
 * @opcode_and_arg: a null terminated array of two elements:
 *	arr[0] = opcode(push), arr[1] = arg(3)
 *	for opcodes that does not require an arg, arr[1] = NULL
 *
 * @container: doubly linked list serves as the container for monty
 *
 * Description: global variables for the program
 */
typedef struct global_vars
{
	size_t mode;
	size_t line_number;
	char **opcode_and_arg;
	stack_t *container;
} monty_data_t;

extern monty_data_t monty_data;

/* utility functions */
void initialize_monty_data(void);
void error_handler(char *error_msg, char *file_name);
void tokenize_string(char *str);
void (*get_function(char *opcode))(stack_t **container, unsigned int);
void free_and_close_resources(FILE *file_stream, char *line_buffer);

/* helper functions for stack and queue ops */
void add_dnodeint_end(stack_t **head, const int n);
void add_dnodeint(stack_t **head, const int n);
void free_container(stack_t **head);

/** stack and queue operations */
void push(stack_t **container, unsigned int line_number);
void pall(stack_t **container, unsigned int line_number);
void stack(stack_t **container, unsigned int line_number);
void queue(stack_t **container, unsigned int line_number);

#endif /* MONTY_H */
