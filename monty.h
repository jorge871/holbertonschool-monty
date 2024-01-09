#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*--------- Structs --------------*/
/**
 * struct stack_s - doubly linked list
 * representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct commands - commands that use the structure.
 * @line_number: The line number where the command appears in the script.
 * @passed_arguments: Amount of arguments passed for the string.
 * @mode: The mode of command.
 * @next: This is the node next.
 * Desctiption: opcode and its function
 * for stack, queues, LIFO, FIFO.
*/
typedef struct commands
{
	int mode;
	unsigned int line_number;
	char *passed_arguments[2];
	struct commands *next;
} cmnds;

extern cmnds *cb;

cmnds *add_node(cmnds **cb, char *c, int b);

/*------------------ Auxiliars Functions ------------------*/
int search_hsh(char **r);
void select_options(stack_t **stack);
void free_all(stack_t **stack);
int is_integer(char *str);
void my_push(stack_t **stack, unsigned int line_number);
/*---------------- Principal Functions -----------------------*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif
