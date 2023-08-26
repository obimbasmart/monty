#include "monty.h"


/**
 * get_function - get the function pointer base on the opcode
 * @opcode: the opcode
 *
 * Return: function pointer
 */
void (*get_function(char *opcode))(stack_t **container, unsigned int)
{
	int arr_size, index;

	instruction_t arr_funcs[] = {
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "pop", pop },
		{ "swap", swap },
		{ "add", add },
		{ "sub", sub },
		{ "mul", mul },
		{ "div", _div },
		{ "mod", mod },
		{ "pchar", pchar },
		{ "pstr", pstr },
		{ "rotl", rotl },
		{ "stack", stack },
		{ "queue", queue }
	};

	if (!opcode)
		return (NULL);

	arr_size = 15;
	index = 0;
	while (index < arr_size)
	{
		if (strcmp(arr_funcs[index].opcode, opcode) == 0)
			return (arr_funcs[index].f);
		index++;
	}
	return (NULL);
}

/**
 * initialize_monty_data - initialize all global vars to default
 *
 * Return: void
 */
void initialize_monty_data(void)
{
	monty_data.line_buffer = NULL;
	monty_data.mode = STACK;
	monty_data.container = NULL;
	monty_data.line_number = 0;
	monty_data.opcode_and_arg = malloc(sizeof(char *) * TOKEN_BUFFERSIZE);
	if (!monty_data.opcode_and_arg) /* malloc failed */
		error_handler(0, "Error: malloc failed", NULL, NULL);
}

/**
 * error_handler - handle error and print error msg
 * @error_msg: error message associated for the error
 * @file_name: name of file passed to monty program
 * @line_number: command line that caused the error
 * @opcode: command that caused the error
 *
 * Return nothing
 */
void error_handler(unsigned int line_number, char *error_msg,
		   char *file_name, char *opcode)
{
	if (file_name)
		dprintf(STDERR_FILENO, "%s %s\n", error_msg, file_name);

	else if (opcode && line_number)
		dprintf(STDERR_FILENO, "L%u: %s %s\n", line_number, error_msg, opcode);

	else if (line_number)
		dprintf(STDERR_FILENO, "L%u: %s\n", line_number, error_msg);

	else
		dprintf(STDERR_FILENO, "%s\n", error_msg);

	free_and_close_resources();
	exit(EXIT_FAILURE);
}


/**
 * tokenize_string - tokenize an string into opcode and argument
 * @str: string to tokenize
 *
 * Return: an array of strings(tokens) e.g ["push", "3"], ["pall"]
 */
void tokenize_string(char *str)
{
	int index = 0;
	char **toks = monty_data.opcode_and_arg;
	char *token;
	const char *delim = " \b\t\n";

	if (toks == NULL)
		error_handler(0, "Error: malloc failed", NULL, NULL);

	token = strtok(str, delim);
	while (token != NULL || index < 2)
	{
		toks[index] = token;
		index++;

		token = strtok(NULL, delim);
	}
	toks[index] = NULL;

}

/**
 * free_and_close_resources - free all dynamically allocated
 * memory and close open file streams
 *
 * Return: nothing
 */
void free_and_close_resources(void)
{
	free(monty_data.opcode_and_arg);
	free(monty_data.line_buffer);

	if (monty_data.file_stream)
		fclose(monty_data.file_stream);
	free_container(&monty_data.container);
}
