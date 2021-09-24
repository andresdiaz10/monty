#include "monty.h"
/**
 * empty - check if is a empty line
 * @line: line to check
 *
 * Return: it the line is empty 1 / Otherwise 0
 */
int empty(char *line)
{
	size_t i;
	size_t j;
	char *delim = " \n\t\a\b";

	for (i = 0 ; *(line + i) ; i++)
	{
		for (j = 0 ; *(delim + j) ; j++)
		{
			if (*(line + i) == *(delim + j))
				break;
		}
		if (*(delim + j) == '\0')
			return (0);
	}
	return (1);
}
/**
 * free_word - free the array with tokenized words
 *
 * Return: none
 */
void free_word(void)
{
	size_t index;

	if (!(token))
		return;
	for (index = 0 ; *(token + index) ; index++)
		free(*(token + index));
	free(token);
}
/**
 * word_lenght - lenght of the word
 *
 * Return: lenghy
 */
size_t word_lenght(void)
{
	size_t lenght = 0;

	while(*(token + lenght))
		lenght++;
	return (lenght);
}

/**
 * last_token - set last word of token
 * @i: a
 *
 * Return: none
 */
void last_token(int i)
{
	char **word = NULL;
	size_t index = 0;
	size_t lenght = word_lenght();
	char *buffer = NULL;

	word = malloc(sizeof(char *) * (2 + lenght));
	if (!(word))
	{
		alloc_message();
		return;
	}
	while (index < lenght)
	{
		*(word + index) = *(token + index);
		index++;
	}
	buffer = int_to_str(i);
	if (!(buffer))
	{
		free(word);
		alloc_message();
		return;
	}
	*(word + i++) = buffer;
	*(word + i) = NULL;
	free(token);
	token = word;
}
