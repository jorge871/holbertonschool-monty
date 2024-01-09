#include "monty.h"
/**
 * free_all - This is a function that free the nodes.
 * @stack: Stack is address of the linked lists.
*/
void free_all(stack_t **stack)
{
	stack_t *temporal = *stack, *next;

	if (*stack != NULL)
	{
		while (temporal != NULL)
		{
			next = temporal->next;
			free(temporal);
			temporal = next;
		}
	}
}