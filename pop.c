#include "monty.h"
/**
 * pop - Function that removes the top element from the stack.
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}