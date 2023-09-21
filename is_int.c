#include <ctype.h>
#include "monty.h"
/**
 * is_integer - Check if a string represents a valid integer.
 *
 * @str: The string to be checked.
 * Return: 1 if str is a valid integer, 0 otherwise.
 */
int is_integer(const char *str)
{

	int i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
