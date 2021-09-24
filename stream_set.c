#include "monty.h"
/**
 * check_delim - determine if the line have a delim 
 * @c: line separete in char
 *
 * Return: 1 if true / 0 if false
 */
int check_delim(char c)
{
	char *delim = " \n\t\a\b";
	int index = 0;

	while (*(delim + index))
	{
		if (c == *(delim + index))
			return (1);
		index++;
	}
	return (0);
}
/**
 * count_words - count the words in the line given a delim
 * @line: a string to count the words
 *
 * Return: a count of the words in the line
 */
int count_words(char *line)
{
	int word_count = 0;
	short int flag = 1;/*Count the first word*/
	int index = 0;
	short int check;
	while (*(line + index))
	{
		check = check_delim(*(line + index));
		if (check)
			flag = 1;
		else if (flag)
		{
			flag = 0;
			word_count++;
		}
		index++;
	}
	return (word_count);
}
/**
 * separate_word - get a line stream and separates with a delim
 * @line: a string to separate
 *
 * Return: a pointer with a array
 */
char **separate_word(char *line)
{
	char **word_array = NULL;
	int word_count;
	int word_lenght;
	int index = 0;
	int aux;

	if (!(line) || !(*line))
		return (NULL);
	word_count = count_words(line);
	if (word_count == 0)
		return (NULL);
	word_array = malloc(sizeof(char *) * (word_count + 1));
	if (!(word_array))
		return (NULL);
	while (index < word_count)
	{
		aux = 0;
		if (check_delim(*line))
			line = pass_word(line);
		word_lenght = wordlen(line);
		word_array[index] = malloc(sizeof(char) * (word_lenght + 1));
		if (!(word_array[index]))
		{
			while (index >= 0)
			{
				index--;
				free(word_array[index]);
			}
			free(word_array);
			return (NULL);
		}
		while (word_lenght > aux)
		{
			word_array[index][aux] = *(line + aux);
			aux++;
		}
		word_array[index][aux] = '\0';
		line = pass_word(line);
		index++;
	}
	word_array[index] = NULL;
	return (word_array);
}
/**
 * pass_word - pass to the next
 * @line: line to pass
 *
 * Return: a pointer to the next
 */
char *pass_word(char *line)
{
	int index = 0;
	short int flag = 0;
	while (*(line + index))
	{
		if (check_delim(line[index]))
			flag = 1;
		else if (flag)
			break;
		index++;
	}
	return (line + index);
}
/**
 * wordlen - count the word lenght in the line
 *
 * @line: string to count the lenght in the word
 * 
 * Return: the word lenght
 */
int wordlen(char *line)
{
	int word_lenght = 0;
	short int flag = 1;
	int index = 0;

	while (*(line + index))
	{
		if (check_delim(line[index]))
			flag = 1;
		else if (flag)
			word_lenght++;
		if (check_delim(line[index]) && (word_lenght > 0))
			break;
		index++;
	}
	return (word_lenght);
}
