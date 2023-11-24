#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

/**
 * factors - factoring prime number
 * line: string of the number to be factorized
 * Return: 0 success | -1 fail
 */
int factors(char *line)
{
	long int number = atoi(line);
	long int mid = number / 2, omid = number - mid, i, j;

	for (i = 2; i <= mid; i++)
	{
		for (j = number - 1; j >= omid; j--)
		{
			if (i * j == number)
			{
				printf("%ld=%ld*%ld\n", number, j, i);
				return (0);
			}
		}	
	}

	return (-1);

}
/**
 * main - entry point
 * argc: number of arguments
 * argv: vector of arguments
 * Return: 0 succuss
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *stream;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Can't read the file\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		read = getline(&line, &len, stream);
		if (read == 0 || read == -1)
			break;
		factors(line);
	}
	free(line);	
	fclose(stream);
	return (0);
}
