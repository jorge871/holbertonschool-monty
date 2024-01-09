#include "monty.h"
/**
 * is_integer - checks if s could be converted to an decimal int
 * @str: sourcer string
 * Return: 0 on success, otherwise 1
 */
int is_integer(char *str)
{
	size_t i;

	if (!str)
		return (1);
	for (i = 0; str[i]; i++)
	{
		if ((str[i] < 48 || str[i] > 57) && (str[i] != '-'))
			return (1);
	}
	return (0);
}