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