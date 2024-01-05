#include "monty.h"
#include <ctype.h>

/**
 * push - This function is used to push a value.
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *push_stack;
    char *arg = strtok(NULL, " \n");

    if (!arg || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(arg);

    push_stack(*stack, value);
}
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
