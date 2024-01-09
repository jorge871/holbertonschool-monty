#include "monty.h"
/**
 * my_push - push on queue mode
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void my_push(stack_t **stack, unsigned int line_number)
{
	stack_t *my_push = NULL;

	my_push = malloc(sizeof(stack_t));
	if (!my_push)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	if (is_integer(cb->passed_arguments[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_all(stack);
		free(my_push);
		exit(EXIT_FAILURE);
	}
	my_push->n = atoi(cb->passed_arguments[1]);
	my_push->next = *stack;
	my_push->prev = NULL;
	if (*stack)
		(*stack)->prev = my_push;
	*stack = my_push;
}