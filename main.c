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
	/* int i; */
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

	/* Allocate memory for opcode_and_arg */
	monty_data.opcode_and_arg = malloc(sizeof(char *) * 2);
	if (monty_data.opcode_and_arg == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (EXIT_FAILURE);
	}

	while (getline(&line_buffer, &n_line, file_stream) != -1)
	{
		monty_data.line_number += 1;

		tokenize_string(line_buffer);

		func = get_function(monty_data.opcode_and_arg[0]);
		if (func)
			func(&monty_data.container, monty_data.line_number);

	}

	fclose(file_stream);
	free(line_buffer);
	/* for (i = 0; i < 2; i++) */
	/* { */
	/* 	if (monty_data.opcode_and_arg[i]) */
	/* 		free(monty_data.opcode_and_arg[i]); */
	/* } */
	free(monty_data.opcode_and_arg);
	return (EXIT_SUCCESS);
}
