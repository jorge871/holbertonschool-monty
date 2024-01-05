#include "monty.h"
/**
 * pint - This function is in charge of adding a new node at the end of the list.  
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
void pint(custom_stack_t **stack, unsigned int line_number)
{
    custom_stack_t *temp = *stack;

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
/**
 * swap - This function is use for swaps the top two elements of the stack.
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
void swap(custom_stack_t **stack, unsigned int line_number)
{
    custom_stack_t *temp = *stack;
	size_t r = 1;

	for (; temp && temp->next; temp = temp->next, r++)
		;
	if (r < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	if (r == 2)
	{
		(*stack)->prev = temp;
		temp->next = (*stack);
		(*stack)->next = NULL;
		*stack = temp;
		(*stack)->prev = NULL;
		return;
	}
	temp->prev = temp->prev->prev;
	temp->prev->next->next = NULL;
	temp->next = temp->prev->next;
	temp->prev->next->prev = temp;
	temp->prev->next = temp;
}
/**
 * nop - This function doesn’t do anything.
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
void nop(custom_stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
/**
 * add - This function is use for adds the top two elements of the stack.
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
void add(custom_stack_t **stack, unsigned int line_number)
{
    custom_stack_t *temp = *stack;
	size_t r = 1;

	for (; temp && temp->next; temp = temp->next, r++)
		;
	if (r < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	temp->prev->n += temp->n;
	pop(stack, line_number);
}
