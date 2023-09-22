#include <stdio.h>

/**
 * main - prime numbers
 *
 * Return: Always 0.
 */

int main(void)
{
	long int nbr = 612852475143;
	long int nbr_1;

	for (nbr_1 = 2; nbr_1 < nbr; nbr_1++)
	{
		if (nbr % nbr_1 == 0)
		{
			nbr = nbr / nbr_1;
		}
	}
	printf("%ld\n", nbr_1);
	return (0);
}
