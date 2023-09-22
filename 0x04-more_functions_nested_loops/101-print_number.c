#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int _putchar(char c);

/**
 * print_number - prints numbers
 * @n: number to be printed
 * Return:void
 */

void print_number(int n)
{

	unsigned int nbr;

	if  (n < 0)
	{
		nbr = -n;
		_putchar('-');
	}

	else
	{
		nbr = n;
	}

	if (nbr / 10)
	{
		print_number(nbr / 10);
	}

	_putchar((nbr % 10) + '0');
}
