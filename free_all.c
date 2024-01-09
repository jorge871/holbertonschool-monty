#include "monty.h"
/**
 * free_all - This is a function that free the nodes.
 * @stack: Stack is address of the linked lists.
*/
void free_all(stack_t **stack)
{
	stack_t *temporal = *stack, *next;
	while (temporal)
	{
		next = temporal->next;
		free(temporal);
		temporal = next;
	}
	*stack = NULL;
}
