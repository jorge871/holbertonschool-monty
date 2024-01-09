#include "monty.h"
/**
 * push - This function is used to push a value.
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *temporal = *stack;

	if (cb->mode)
	{
		my_push(stack, line_number);
		return;
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	if (is_integer(cb->passed_arguments[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_all(stack);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(cb->passed_arguments[1]);
	new_node->next = NULL;
	if (!(*stack))
	{
		new_node->prev = *stack;
		*stack = new_node;
		return;
	}
	while (temporal->next)
		temporal = temporal->next;
	temporal->next = new_node;
	new_node->prev = temporal;
}