#include "monty.h"

/**
 * free_all - This is a function that free the nodes.
 * @stack: Stack is address of the linked lists.
*/
void free_all(stack_t **stack)
{
	stack_t *temporal = NULL;
	cmnds *temporal2;

	for (; *stack; *stack = (*stack)->next, free(temporal))
		temporal = *stack;
	for (; cb; cb = cb->next, free(temporal2))
	{
		temporal2 = cb;
		free(cb->passed_arguments[1]);
		free(cb->passed_arguments[0]);
	}
}