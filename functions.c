#include "monty.h"

/**
 * search_hsh - Function for search the number of line.
 * @r: Line to read.
 *
 * Return: 1 if find the line, otherwise 0
 */
int search_hsh(char **r)
{
    int v;

    for (v = 0; (*r)[v] && ((*r)[v] == ' ' || (*r)[v] == '\t'); v++)
		;
	if ((*r)[v] == '#')
		return (1);
	for (v = 0; (*r)[v] && (*r)[v] != '#'; v++)
		;
	(*r)[v] = '\0';
	return (0);
}

/**
 * add_node - this function is used to add a node to the end of the list of commands already analyzed.
 * @cb: This is the head of the linked list.
 * @c: This is the command to be analyzed.
 * @b: This is the line number of the script.
 * 
 * Return: New node; NULL if it is fail.
*/

cmnds *add_node(cmnds **cb, char *c, int b)
{
    cmnds *temp = *cb, *new = NULL;
    char *str;

    new = malloc(sizeof(cmnds));
    if(!new)
    {
        return (NULL);
    }
    new->passed_arguments[0] = strdup(strtok(c, " \t"));
    if (!(new->passed_arguments[0]))
    {
        free(new);
        return (NULL);
    }
    str = strtok(NULL, " \t");
    if(str)
    {
        new->passed_arguments[1] = strdup(str);
        if(!(new->passed_arguments[1]))
        {
            free(new->passed_arguments[1]);
            free(new);
            return (NULL);
        }

    }
    else
    {
        new->passed_arguments[1] = NULL;
        new->line_number = b;
        new->next = NULL;
        new->mode = 0;
    }

        if(!(*cb))
        {
            *cb = new;
            return (new);   
        }
        for (; temp->next; temp = temp->next)

            continue;
        temp->next = new;
        return (new);
}
/**
 * my_push - push on queue mode
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void my_push(stack_t **stack, unsigned int line_number)
{
	stack_t *my_push = NULL;

	my_push = malloc(sizeof(stack_t));
	if (!my_push)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	if (is_integer(cb->passed_arguments[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_all(stack);
		free(my_push);
		exit(EXIT_FAILURE);
	}
	my_push->n = atoi(cb->passed_arguments[1]);
	my_push->next = *stack;
	my_push->prev = NULL;
	if (*stack)
		(*stack)->prev = my_push;
	*stack = my_push;
}