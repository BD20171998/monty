#include "monty.h"

/**
 * err_token - function that handles an initial token which is NULL
 * @token: Char pointer for token read from file
 * @stack: the stack of elements of struct type stack_t
 * @line_num: line number of type unsigned int
 * @line: char pointer for original input read from file
 * @linecopy: Char pointer for copy of original input used for tokenization
 * @fd: File descriptor
 * Return: Void
 */

void err_token(char *token, stack_t **stack, unsigned int line_num, char *line,
	       char *linecopy, FILE *fd)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
		line_num, token);

	free(line);
	free(linecopy);
	free_dlistint(*stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}

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
		linecopy = _strdup(line, &stack, fd);
		token = strtok(linecopy, " \t\n");

		if (token == NULL)
			err_token(token, &stack, i, line, linecopy, fd);

		else if (strcmp(token, "push") == 0)
			push(token, &stack, i, line, linecopy, fd);

		else
			others(token, &stack, i, line, linecopy, fd);
		free(line);
		free(linecopy);
		line = linecopy = NULL;
	}
	free_dlistint(stack);
	fclose(fd);
	return (0);
}
