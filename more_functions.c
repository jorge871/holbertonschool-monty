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
        free (cb->passed_arguments[1]);
        free (cb->passed_arguments[0]);
    }
}

/**
 * select_options - This is the function for execute the options.
 * @stack:Stack is address of the linked lists.
*/

void select_options(stack_t **stack)
{
    int s;
    instruction_t options[] = 
    {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };
    while (options[s].opcode)
    {
        if(!strcmp(options[s].opcode, cb->passed_arguments[0]))
        {
            (options[s].f)(stack, cb->line_number);
            break;
        }
        s++;
    }
    if(!options[s].opcode)
    {
        dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
        cb->line_number, cb->passed_arguments[0]);
        free_all(stack);
        exit(EXIT_FAILURE);
    }
    
}