#include "monty.h"
/**
 * push - Push a int to the data structure
 * @data_structure: pointer to the data structure
 * @line_number: line number to the function is call
 *
 * Return: None
 */
void push(stack_t **data_structure, unsigned int line_number)
{
	int index;
	stack_t *new_data;
	stack_t *aux;

	new_data = malloc(sizeof(stack_t));
	if (!(new_data))
	{
		last_token(alloc_message());
		return;
	}
	if (!(token[1]))
	{
		last_token(int_message(line_number));
		return;
	}
	for (index = 0 ; token[1][index] ; index++)
	{
		if (index == 0 && token[1][index] == '-')
			continue;
		if (token[1][index] < '0' || token[1][index] > '9')
		{
			last_token(int_message(line_number));
			return;
		}
	}
	new_data->n = atoi(token[1]);
	if (see_data_structure(*data_structure) == 0)
	{
		aux = (*data_structure)->next;
		new_data->prev = *data_structure;
		new_data->next = aux;
		if (aux)
			aux->prev = new_data;
		(*data_structure)->next = new_data;
	}
	else
	{
		aux = *data_structure;
		while (aux->next)
			aux = aux->next;
		new_data->prev = aux;
		new_data->next = NULL;
		aux->next = new_data;
	}
}
/**
 * pall - print the values in the data structure
 * @data_structure: a
 * @line_number: a
 *
 * Return: None
 */
void pall(stack_t **data_structure, unsigned int line_number)
{
	stack_t *aux = (*data_structure)->next;

	(void)line_number;
	while(aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
/**
 * pint - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: none
 */
void pint(stack_t **data_structure, unsigned int line_number)
{
	if (!((*data_structure)->next))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		last_token(EXIT_FAILURE);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%d\n", (*data_structure)->next->n);
}
/**
 * swap - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: none
 */
void swap(stack_t **data_structure, unsigned int line_number)
{
	stack_t *aux;

	if (!((*data_structure)->next)|| (*data_structure)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		last_token(EXIT_FAILURE);
		return;
	}
	aux = (*data_structure)->next->next;
	(*data_structure)->next->next = aux->next;
	(*data_structure)->next->prev = aux;
	if (aux->next)
		aux->next->prev = (*data_structure)->next;
	aux->next = (*data_structure)->next;
	aux->prev = *data_structure;
	(*data_structure)->next = aux;
}
/**
 * pop - a
 * @data_structure: a
 * @line_number: a
 *
 * Return: None
 */
void pop(stack_t **data_structure, unsigned int line_number)
{	
	stack_t *aux = NULL;

	if ((*data_structure)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		last_token(EXIT_FAILURE);
		return;
	}
	aux = (*data_structure)->next->next;
	free((*data_structure)->next);
	if (aux)
		aux->prev = *data_structure;
	(*data_structure)->next = aux;
}
