#include "monty.h"
/**
 * nop - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: a
 */
void nop(stack_t **data_structure, unsigned int line_number)
{
	(void)line_number;
	(void)data_structure;
}
/**
 * add - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: a
 */
void add(stack_t **data_structure, unsigned int line_number)
{
	if ((*data_structure)->next == NULL || (*data_structure)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		last_token(EXIT_FAILURE);
		exit(EXIT_FAILURE);
		return;
	}
	(*data_structure)->next->next->n += (*data_structure)->next->n;
	pop(data_structure, line_number);
}

/**
 * sub - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: a
 */
void sub(stack_t **data_structure, unsigned int line_number)
{
	if ((*data_structure)->next == NULL || (*data_structure)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't subb, stack too short\n", line_number);
		last_token(EXIT_FAILURE);
		exit(EXIT_FAILURE);
		return;
	}
	(*data_structure)->next->next->n -= (*data_structure)->next->n;
	pop(data_structure, line_number);
}

/**
 * div - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: a
 */
void div_s(stack_t **data_structure, unsigned int line_number)
{
	if ((*data_structure)->next == NULL || (*data_structure)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
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
	(*data_structure)->next->next->n /= (*data_structure)->next->n;
	pop(data_structure, line_number);
}

/**
 * mul - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: a
 */
void mul(stack_t **data_structure, unsigned int line_number)
{
	if ((*data_structure)->next == NULL || (*data_structure)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		last_token(EXIT_FAILURE);
		exit(EXIT_FAILURE);
		return;
	}

	(*data_structure)->next->next->n *= (*data_structure)->next->n;
	pop(data_structure, line_number);
}
