#include "monty.h"

char **token = NULL;
/**
 * see_data_structure - see if the linked list is a stack or queue
 * @data_structure: a pointer to the linked list
 *
 * Return: a
 */
int see_data_structure(stack_t *data_structure)
{
	if (data_structure->n == 0)
		return (0);
	else if (data_structure->n == 1)
		return (1);
	return (-7);
}
/**
 * exe_line - get line in the stream and init the data structure
 * @stream: A file with the bytecode
 *
 * Return: EXIT_FAILURE if fails / Otherwise EXIT_SUCCESS
 */
int exe_line(FILE *stream)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char *line = NULL; /*Avoid error*/
	size_t len = 0, lenght_prev;
	int aux = EXIT_SUCCESS;
	unsigned int line_number = 0;
	stack_t *data_structure = NULL;

	if (set_data_structure(&data_structure) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, stream) != -1)
	{
	       token = separate_word(line);
	       line_number++;
	       if (!(token))
	       {
		       if (empty(line))
			       continue;
		       free_data_structure(&data_structure);
		       return (alloc_message());
	       }
	       else if (token[0][0] == '#')
	       {
		       free_word();
		       continue;
	       }
	       f = get_operator(token[0]);
	       if (!(f))
	       {
		       aux = bad_operator(token[0], line_number);
		       free_data_structure(&data_structure);
		       free_word();
		       break;
	       }
	       f(&data_structure, line_number);
	       lenght_prev = word_lenght();
	       if (word_lenght() != lenght_prev)
	       {
		       if (token[lenght_prev] && token)
			       aux = atoi(token[lenght_prev]);
		       else
			       aux = EXIT_FAILURE;
		       free_word();
		       break;
	       }
	       free_word();
	}
	free_data_structure(&data_structure);
	if (*line == 0 && line)
	{
		free(line);
		return (alloc_message());
	}
	free(line);
	return (aux);
}
/**
 * set_data_structure - init a basic stack
 * @data_structure: a pointer to a stack_t
 *
 * Return: If everythin is OK EXIT_SUCCESS / otherwise EXIT_FAILURE
 */
int set_data_structure(stack_t **data_structure)
{
	stack_t *aux;

	aux = malloc(sizeof(stack_t));
	if (!(aux))
		return (alloc_message());
	aux->prev = NULL;
	aux->next = NULL;
	aux->n = 0;
	*data_structure = aux;
	return (EXIT_SUCCESS);
}
/**
 * alloc_message - print in the stderr when exist a alloc error
 *
 * Return: EXIT_FAILURE
 */
int alloc_message(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * main - open the file that contain the monty language
 * @ac: number of arguments passed in stdin
 * @av: a pointer to the array
 *
 * Return: a EXIT_SUCCESS if everything es OK/ Othewise EXIT_FAILURE
 */
int main(int ac, char **av)
{
	int exitv;
	FILE *stream;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	stream = fopen(av[1], "r");
	if (!(stream))
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	exitv = exe_line(stream);
	fclose(stream);
	return (exitv);
}
