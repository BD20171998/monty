#include "monty.h"

/**
 * push - function that pushes an element to the stack
 * @token: Char pointer for token read from file
 * @stack: the stack of elements of struct type stack_t
 * @line_num: line number of type unsigned int
 * @line: char pointer for original input read from file
 * @linecopy: Char pointer for copy of original input used for tokenization
 * Return: Void
 */

void push(char *token, stack_t **stack, unsigned int line_num, char *line,
	  char *linecopy)
{
	int n;

	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " \t\n");

		if (strcmp(token, "0") == 0)
		{
			n = 0;
			add_dnodeint(stack, n);
			return;
		}

		n = atoi(token);

		if (n == 0)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
				line_num);
			free(line);
			free(linecopy);
			free_dlistint(*stack);
			exit(EXIT_FAILURE);
		}

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
 * Return: Void
 */

void others(char *token, stack_t **stack, unsigned int line_num, char *line,
	    char *linecopy)
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
	exit(EXIT_FAILURE);
}
