#include "monty.h"
#include <ctype.h>

/**
 * push - This function is used to push a value.
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct custom_stack_node_s
{
    int data;
    struct custom_stack_node_s *next;
} custom_stack_node_t;


void push_stack(custom_stack_t **stack, int value);

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

void push(custom_stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");

    if (!arg || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(arg);

    push_stack(stack, value);
}

void push_stack(custom_stack_t **stack, int value)
{

    custom_stack_node_t *new_node = malloc(sizeof(custom_stack_node_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }


    new_node->data = value;
    new_node->next = **stack;

    *stack = new_node;
}


/**
 * pall - This function prints all values in ascending order.
 * @stack: Stack is address of the linked lists.
 * @line_number: This is the number of line.
*/
void pall(custom_stack_t **stack, unsigned int line_number)
{
    custom_stack_t *current = *stack;

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
void pop(custom_stack_t **stack, unsigned int line_number)
{
    custom_stack_t *temp;

    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
