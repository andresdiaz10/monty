#include "monty.h"
/**
 * mod_s - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: a
 */
void mod_s(stack_t **data_structure, unsigned int line_number)
{
	if ((*data_structure)->next == NULL || (*data_structure)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		last_token(EXIT_FAILURE);
		exit(EXIT_FAILURE);
		return;
	}
	if ((*data_structure)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		last_token(EXIT_FAILURE);
		exit(EXIT_FAILURE);
		return;
	}
	(*data_structure)->next->next->n %= (*data_structure)->next->n;
	pop(data_structure, line_number);
}

/**
 * div - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: a
 */
void stack(stack_t **data_structure, unsigned int line_number)
{
	(void)line_number;
	(*data_structure)->n = 0;
}

/**
 * div - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: a
 */
void queue(stack_t **data_structure, unsigned int line_number)
{
	(void)line_number;
	(*data_structure)->n = 1;
}
