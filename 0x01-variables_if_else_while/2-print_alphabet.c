#include <stdio.h>

/**
 * main - entry point
 *
 * Description: Prints the alphabet in lowercase using putchar
 *
 * Return: 0 (success)
 */

int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		putchar(letter);

	putchar('\n');

	return (0);
}
