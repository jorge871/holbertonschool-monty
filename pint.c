#include "monty.h"
/**
 * pint - This function is in charge of
 * adding a new node at the end of the list.
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	for (; temp->next; temp = temp->next)
		;
	printf("%d\n", temp->n);
}