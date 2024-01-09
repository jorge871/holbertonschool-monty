#include "monty.h"
/**
 * pall - This function prints all values in ascending order.
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}