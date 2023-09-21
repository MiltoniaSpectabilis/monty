#include "monty.h"

/**
 * main - Entry point of the Monty interpreter.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	proc_file(file);

	fclose(file);
	return (EXIT_SUCCESS);
}
