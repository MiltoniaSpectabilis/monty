#include "monty.h"

/**
 * swap - Swap the top two elements of the stack.
 *
 * @stack: A pointer to the stack for stack manipulation.
 * @line_num: The line number in the Monty byte code file.
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = (*stack);
	(*stack) = temp;
}


/**
 * add - Add the top two elements of the stack.
 *
 * @stack: A pointer to the stack for stack manipulation.
 * @line_num: The line number in the Monty byte code file.
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * nop - Do nothing (No operation).
 *
 * @stack: A pointer to the stack for stack manipulation.
 * @line_num: The line number in the Monty byte code file.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
