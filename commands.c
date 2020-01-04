#include "monty.h"

/**
 * isdig - function that determines if a string contains a digit or not
 * @token: Char pointer to be checked
 * Return: 0 if a non-digit character is present, 1 otherwise
 */

int isdig(char *token)
{
	int i = 0;

	while (token[i])
	{
		if (token[i] < '0' || token[i] > '9')
			return (0);

		++i;
	}

	return (1);
}

/**
 * push - function that pushes an element to the stack
 * @token: Char pointer for token read from file
 * @stack: the stack of elements of struct type stack_t
 * @line_num: line number of type unsigned int
 * @line: char pointer for original input read from file
 * @linecopy: Char pointer for copy of original input used for tokenization
 * @fd: File descriptor
 * Return: Void
 */

void push(char *token, stack_t **stack, unsigned int line_num, char *line,
	  char *linecopy, FILE *fd)
{
	int n;

	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " \t\n");

		n = isdig(token);

		if (token == NULL || n == 0)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
				line_num);
			free(line);
			free(linecopy);
			free_dlistint(*stack);
			fclose(fd);
			exit(EXIT_FAILURE);
		}

		n = atoi(token);
		add_dnodeint(stack, n);
		return;
	}

	else
		return;
}

/**
 * others - function that executes opcodes from tokens other than push
 * @token: Char pointer for token read from file
 * @stack: the stack of elements of struct type stack_t
 * @line_num: line number of type unsigned int
 * @line: char pointer for original input read from file
 * @linecopy: Char pointer for copy of original input used for tokenization
 * @fd: File descriptor
 * Return: Void
 */

void others(char *token, stack_t **stack, unsigned int line_num, char *line,
	    char *linecopy, FILE *fd)
{
	int j = 0;

	instruction_t ops[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop}
	};

	while (j < 3)
	{
		if (strcmp(token, ops[j].opcode) == 0)
		{
			ops[j].f(stack, line_num);
			return;
		}

		++j;
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_num,
		token);
	free(linecopy);
	free(line);
	free_dlistint(*stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}
