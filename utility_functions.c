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
		{ "pall", pall}
	};

	arr_size = 2;
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
	monty_data.mode = STACK;
	monty_data.container = NULL;
	monty_data.line_number = 0;
	monty_data.opcode_and_arg = malloc(sizeof(char *) * TOKEN_BUFFERSIZE);
}

/**
 * error_handler - handle error and print error msg
 * @error_msg: error message associated for the error
 * @file_name: name of file passed to monty program
 *
 * Return nothing
 */
void error_handler(char *error_msg, char *file_name)
{
	if (file_name)
	{
		dprintf(STDERR_FILENO, "%s %s\n", error_msg, file_name);
		exit(EXIT_FAILURE);
	}

	dprintf(STDERR_FILENO, "%s\n", error_msg);
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
		error_handler("Error: malloc failed", NULL);

	token = strtok(str, delim);
	while (token != NULL || index < 2)
	{
		toks[index] = token;
		index++;

		token = strtok(NULL, delim);
	}
	toks[index] = NULL;

}
