#include "monty.h"

/**
 * proc_file - Process Monty byte code instructions from a file.
 *
 * @file: Pointer to the file to be processed.
 */
void proc_file(FILE *file)
{
	char line[1024];
	char *opcode = NULL;
	size_t len;
	stack_t *stack = NULL;
	unsigned int line_num = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		len = strlen(line);

		if (len == 0 || (strspn(line, " \t") == len - 1 && line[len - 1] == '\n'))
		{
			line_num++;
			continue;
		}

		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		line_num++;
		opcode = strtok(line, " \t\n");

		exec_instruct(opcode, &stack, line_num);
	}

	free_stack(&stack);
}

