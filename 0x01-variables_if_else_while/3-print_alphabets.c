#include <stdio.h>

/**
 * main - entry point
 *
 * Description: Prints the alphabet in lowercase and then in uppercase using putchar
 *
 * Return: 0 (success)
 */

int main(void)
{
	char lowercase;
	char uppercase;

	for (lowercase = 'a'; lowercase <= 'z'; lowercase++)
		putchar(lowercase);

	for (uppercase = 'A'; uppercase <= 'Z'; uppercase++)
		putchar(uppercase);

	putchar('\n');

	return (0);
}
