#include "monty.h"

/**
 * add - adds top two stack mems
 * @stack: double list
 * @linenumber: line
 */
void add(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *freeable;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		freeable = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(freeable);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
				monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
}
/**
 * push_queue - add node to end list
 * @argument: int
 */
void push_queue(char *argument)
{
	int data;
	stack_t *new, *location;

	if (!check_input(argument))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
				monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}

	data = atoi(argument);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_it_all();
		exit(EXIT_FAILURE);
	}
	location = monty.stack;
	new->n = data;
	new->next = NULL;
	if (!location)
	{
		new->prev = NULL;
		monty.stack = new;
		return;
	}
	while (location->next)
	{
		location = location->next;
	}
	location->next = new;
	new->prev = location;
}
/**
 * pint - print int in stack
 * @stack: double list
 * @linenumber: line
 */
void pint(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", monty.line_number);
		free_it_all();
		exit(EXIT_FAILURE);
	}
}