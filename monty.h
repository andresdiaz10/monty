#ifndef __MONTY_H__
#define __MONTY_H__

#define _POSIX_C_SOURCE 200809
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
extern char **token;
/**
 *struct stack_s - doubly linked list representation of a stack (or queue)
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

int exe_line(FILE *stream);
int set_data_structure(stack_t **data_structure);
int alloc_message(void);
int see_data_structure(stack_t *data_structure);

int check_delim(char c);
int count_words(char *line);
char **separate_word(char *line);
char *pass_word(char *line);
int wordlen(char *line);

void free_data_structure(stack_t **data_structure);

int empty(char *line);
void free_word(void);
size_t word_lenght(void);
void last_token(int i);

void (*get_operator(char *opcode))(stack_t **data_structure, unsigned int line_number);
int bad_operator(char *opcode, unsigned int line_number);

void push(stack_t **data_structure, unsigned int line_number);
void pall(stack_t **data_structure, unsigned int line_number);
void pint(stack_t **data_structure, unsigned int line_number);
void swap(stack_t **data_structure, unsigned int line_number);
void pop(stack_t **data_structure, unsigned int line_number);

int abs(int n);
int num_lenght(int n, int base);
void set_buffer(int n, unsigned int base, char *buff, int buff_size);
char *int_to_str(int n);
int int_message(unsigned int line_number);
#endif
