#include "monty.h"


/**
 * main - program that copies the content of a file to another file
 * @argc: - Int of arguments passed into program including command
 * @argv: - Array of pointers to the strings of arguments passed
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	char *line = NULL, *linecopy = NULL, *token;
	unsigned int count, i;
	size_t len = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		err_msg("USAGE: monty ", "file", EXIT_FAILURE);

	fd = fopen(argv[1], "r");

	if (fd == NULL)
		err_msg("Error: Can't open file ", argv[1], EXIT_FAILURE);

	count = linecount(fd);

	fd = fopen(argv[1], "r");

	for (i = 1; i < count + 1; i++)
	{
		getline(&line, &len, fd);
		linecopy = _strdup(line);
		token = strtok(linecopy, " \t\n");

		if (strcmp(token, "push") == 0)
			push(token, &stack, i, line, linecopy);

		else
			others(token, &stack, i, line, linecopy);

		free(line);
		free(linecopy);
	}
	free(line);
	free(linecopy);
	free_dlistint(stack);
	fclose(fd);
	return (0);
}
