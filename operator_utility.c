#include "monty.h"

/**
 * get_operator - if the word match with a operator return a function 
 * @opcode: string to match with the operator
 *
 * Return: None
 */
void (*get_operator(char *opcode))(stack_t **data_structure, unsigned int line_number)
{
	instruction_t operators[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"pop", pop},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"div", div_s},
		{"mul", mul},
		{"mod", mod_s},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int index;

	for (index = 0 ; operators[index].opcode ; index++)
	{
		if (strcmp(opcode, operators[index].opcode) == 0)
			return (operators[index].f);
	}

	return (NULL);
}
/**
 * bad_operator - print error message
 * @opcode: string with the operator
 * @line_number: line when the problem occurs
 *
 * Return: EXIT_FAILURE
 */
int bad_operator(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}
