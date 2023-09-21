#include "monty.h"

/**
 * free_stack - Free all elements of a stack.
 *
 * @stack: A pointer to the stack to be freed.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
