#include <stdio.h>

/**
 * factorize - Factorize a number
 * @n: The number to factorize
 * Return: Nothing
 */
void factorize(long n)
{
	long i;

	printf("%ld=", n);

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			printf("%ld*%ld\n", n / i, i);
			return;
		}
	}
	printf("%ld*%ld\n", 1L, n);
}
/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: The command line arguments
 * Return: 0 if successful, otherwise 1
 */
int main(int argc, char *argv[])
{
	FILE *file;
	long number;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while (fscanf(file, "%ld", &number) == 1)
	{
		factorize(number);
	}

	fclose(file);
	return (0);
}
