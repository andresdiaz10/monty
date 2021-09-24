#include "monty.h"
/**
 * free_data_structure - free the data structure
 * @data_structure: a pointer to the data structure
 *
 * Return: None
 */
void free_data_structure(stack_t **data_structure)
{
	stack_t *aux = *data_structure;

	while (*data_structure)
	{
		aux = (*data_structure)->next;
		free(*data_structure);
		*data_structure = aux;
	}
}
