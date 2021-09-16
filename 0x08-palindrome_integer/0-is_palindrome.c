#include "palindrome.h"
#include <stdio.h>

/**
 * reverse - Reverses a number a leaves the reverse value in an int pointer
 *
 * @n: Value to reverse
 * @rev: Pointer to number where reverse value will be stored
 *
 * Return: No Return
 */
void reverse(unsigned long n, unsigned long *rev)
{
	if (n > 0)
	{
		*rev = *rev * 10 + (n % 10);
		n /= 10;
		reverse(n, rev);
	}

}

/**
 * is_palindrome - Entry point
 *
 * @n: Number to Evaluate
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0;

	reverse(n, &rev);

	if (rev == n)
		return (1);

	return (0);
}
