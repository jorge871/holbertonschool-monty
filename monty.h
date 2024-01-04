#ifndef MHF
#define MHF

/*Libraries that the functions uses*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>
#include <errno.h>
#include <stdbool.h>

/*---------------------------------------------------------------------------*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
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

/*---------------------------------------------------------------------------*/

/**
 * struct monty_s - global struct to hold all the things
 * @file: monty file
 * @line: line we are interpreting
 * @stack: the stack we are building
 * @line_number: current line number read
 * @is_queue: flag for stack/ queue
 *
 * Description: this is our single global and holds everything we need.
 */
typedef struct monty_s
{
	FILE *file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
	bool is_queue;
} monty_t;

/*---------------------------------------------------------------------------*/

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 *
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*---------------------------------------------------------------------------*/ 

monty_t monty;

void pop(stack_t **stack, __attribute__((unused))unsigned int linenumber);
void swap(stack_t **stack, __attribute__((unused))unsigned int linenumber);
void nop(stack_t **stack, __attribute__((unused))unsigned int linenumber);
void pall(stack_t **stack, __attribute__((unused))unsigned int linenumber);
void push(char *argument);
void init_montyStruct(void);
int main(int argc, char **argv);
void op_choose(stack_t **stack, char *opcode);
void read_line(void);
void open_up(int argc, char *filename);


#endif