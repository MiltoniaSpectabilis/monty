#include "monty.h"

/**
 * push - Push an element onto the stack.
 *
 * @stack: A pointer to the stack for stack manipulation.
 * @line_num: The line number in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_num)
{
	char *arg;
	int value;
	stack_t *new_node;

	arg = strtok(NULL, " \n\t");
	if (!arg || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Print all elements of the stack.
 *
 * @stack: A pointer to the stack for stack manipulation.
 * @line_num: The line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	(void)line_num;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


/**
 * pint - Print the value at the top of the stack.
 *
 * @stack: A pointer to the stack for stack manipulation.
 * @line_num: The line number in the Monty byte code file.
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Remove the top element from the stack.
 *
 * @stack: A pointer to the stack for stack manipulation.
 * @line_num: The line number in the Monty byte code file.
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
