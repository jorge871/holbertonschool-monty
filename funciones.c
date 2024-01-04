#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg;
    int value;

    if (!stack || !line)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    arg = strtok(NULL, " \n");
    if (!arg || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    push_stack(stack, value);
}

/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
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
 * is_integer - Checks if a string represents an integer.
 * @str: The string to check.
 * Return: 1 if the string is an integer, 0 otherwise.
 */
int is_integer(char *str)
{
    if (!str)
        return 0;

    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}