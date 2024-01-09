#include "monty.h"

/**
 *free_it_all - frees all
 *
 *Return: Void
 */
void free_it_all(void)
{
	fclose(monty.file);
	free(monty.line);
	free_build(monty.stack);
}
/**
 * free_build - frees the stack
 * @h: the head of stack
 *
 *
 */
void free_build(stack_t *h)
{
	stack_t *temp;
	stack_t *location = h;

	while (location)
	{
		temp = location;
		location = location->next;
		free(temp);
	}
}