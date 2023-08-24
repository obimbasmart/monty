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
	char *file_name;
	size_t n_line;
	void (*func)(stack_t **, unsigned int); /* function pointer */

	n_line = 0;
	file_name = argv[1];
	initialize_monty_data();
	if (ac != 2)
		error_handler(0, "USAGE: monty file", NULL, NULL);

	monty_data.file_stream = fopen(file_name, "r");
	if (monty_data.file_stream == NULL)
		error_handler(0, "Error: Can't open file", file_name, NULL);

	while (getline(&monty_data.line_buffer, &n_line,
		monty_data.file_stream) != -1)
	{
		monty_data.line_number += 1;
		tokenize_string(monty_data.line_buffer);

		func = get_function(monty_data.opcode_and_arg[0]);
		if (func)
			func(&monty_data.container, monty_data.line_number);
		else
		{
			error_handler(monty_data.line_number, "unknown instruction",
					NULL, monty_data.opcode_and_arg[0]);

			free_and_close_resources();
		}

	}

	free_and_close_resources();
	return (EXIT_SUCCESS);
}
