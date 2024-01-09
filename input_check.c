#include "monty.h"
/**
 * check_input- check the int for intness
 * @str: the string we check
 *
 * Return: false unless int
 */
bool check_input(char *str)
{
	int i = 0;

	if (!str)
	{
		return (false);
	}
	if (str[0] != '-' && !isdigit(str[0]))
	{
		return (false);
	}
	for (i = 1; str[i]; i++)
	{
		if (!isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}