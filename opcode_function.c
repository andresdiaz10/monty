#include "monty.h"

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
}
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
