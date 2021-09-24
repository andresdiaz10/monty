#include "monty.h"
/**
 * abs - get abs of a int
 * @n: int to get abs
 *
 * Return: the abs of n
 */
int abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}
/**
 * num_lenght - set the lenght
 * @n: lenght of the number
 * @base: base of the number
 *
 * Return: the lenght of the number
 */
int num_lenght(int n, int base)
{
	int lenght = 1;

	while (n > base - 1)
	{
		n /= base;
		lenght++;
	}
	return(lenght);
}
/**
 * set_buffer - set the buffer 
 * @n: numbe to use
 * @base: base of the number
 * @buff: buffer to set
 * @buff_size: size of buff
 *
 * Return: none
 */
void set_buffer(int n, unsigned int base, char *buff, int buff_size)
{
	int index = buff_size - 1;
	int digit;

	*(buff + buff_size) = '\0';
	while (index >= 0)
	{
		digit = n % base;
		if (digit > 9)
			*(buff + index) = digit + 87;
		else
			*(buff + index) = digit + '0';
		n /= base;
		index--;
	}
}
/**
 * int_to_str - pointer to the str
 * @n: number to string
 *
 * Return: a new str pointer with the int
 */
char *int_to_str(int n)
{
	int lenght = 0;
	char *buff;
	int aux;

	aux = abs(n);
	lenght = num_lenght(aux, 10);
	if (n < 0)
		lenght++;
	buff = malloc(sizeof(char) * (lenght + 1));
	if (!(buff))
		return (NULL);
	set_buffer(aux, 10,buff, lenght);
	if (n < 0)
		buff[0] = '-';
	return (buff);
}
/**
 * int_message - print error when a no int argument is passed.
 * @line_number: line when the error occurs.
 *
 * Return: EXIT_FAILURE.
 */
int int_message(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
