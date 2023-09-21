#include "monty.h"


/**
 * exec_instruct - Execute a Monty opcode instruction.
 *
 * @opcode: The Monty opcode to be executed.
 * @stack:  A pointer to the stack for stack manipulation.
 * @line_num: The line number in the Monty byte code file.
 */
void exec_instruct(char *opcode, stack_t **stack, unsigned int line_num)
{
	instruction_t instructs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i = 0;


	for (i = 0; instructs[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructs[i].opcode) == 0)
		{
			instructs[i].f(stack, line_num);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
