#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/* betty style doc for function main goes there */

/**
 * main-Entry point 
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n;
	int ld;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	ld = n \ 10;

	if (ld > 5)
	{	
		printf("last digit of %d is %d and is greater than 5\n", n);
	}
	else if (ld < 5)
	{
		printf("last digit of %d is %d and is less than 6 and not 0\n", n);
	}
	else 
	{
		printf("last digit of %d is %d and is 0\n", n);
	}
	return (0);
}
