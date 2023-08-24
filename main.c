#define _POSIX_C_SOURCE 200809L
#include "monty.h"

monty_data_t monty_data; /* define global variable */

/**
 * main - main program
 * @ac: number of args passed to program
 * @argv: array of args passed to program
 *
 * Return: success
 */
int main(int ac, char **argv)
{
	FILE *file_stream;
	char *line_buffer, *file_name;
	size_t n_line;
	void (*func)(stack_t **, unsigned int); /* function pointer */

	n_line = 0;
	file_name = argv[1];
	line_buffer = NULL;
	initialize_monty_data();
	if (ac != 2)
		error_handler("USAGE: monty file", NULL);

	file_stream = fopen(file_name, "r");
	if (file_stream == NULL)
		error_handler("Error: Can't open file", file_name);

	while (getline(&line_buffer, &n_line, file_stream) != -1)
	{
		monty_data.line_number += 1;
		tokenize_string(line_buffer);

		func = get_function(monty_data.opcode_and_arg[0]);
		if (func)
			func(&monty_data.container, monty_data.line_number);
		else
		{
			dprintf(STDERR_FILENO, "L%lu: unknown instruction %s\n",
					monty_data.line_number, monty_data.opcode_and_arg[0]);
			free_and_close_resources(file_stream, line_buffer);
			exit(EXIT_FAILURE);
		}

	}

	free_and_close_resources(file_stream, line_buffer);
	return (EXIT_SUCCESS);
}
