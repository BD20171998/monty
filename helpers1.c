#include "holberton.h"

/**
 * free_dlistint - function that free a dlistint_t list
 * @head: Const pointer to head node for linked dlistint_t list
 * Return: Void
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	temp = head;

	if (head == NULL)
		return;

	while (temp != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}

}

/**
 * add_dnodeint - function that adds a new node at the beginning of a
 * stack_t list
 * @head: Const pointer to head node for linked dlistint_t list
 * @n: Const integer of node to be added
 * Return: the address of the new element, or NULL if it failed
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (*head);
	}

	(*head)->prev = new;
	new->next = *head;

	*head = new;

	return (*head);
}

/**
 * _strdup - function that returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string given as a parameter
 * @str: - Char string to be copied
 * Return: Char pointer to the duplicated string. Return NULL if insufficient
 * memory was available to array or if array is NULL
 */

char *_strdup(char *str)
{
	char *dup;

	int i, l;

	if (str == NULL)
		return (NULL);

	l = 0;

	for (i = 0; str[i] != '\0'; i++)
		l++;

	dup = malloc(sizeof(char) * l + 1);

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < l ; i++)
		dup[i] = str[i];

	dup[l] = '\0';

	return (dup);

}

/**
 * linecount - function that returns the total line count read
 * @fd: - File descriptor for file to be read
 * Return: Unisgned int of the line number
 */

unsigned int linecount(FILE *fd)
{
	unsigned int count = 0;
	char c;

	for (c = getc(fd); c != EOF; c = getc(fd))
		if (c == '\n')
			count = count + 1;
	fclose(fd);
	return (count);
}

/**
 * err_msg - function that returns an error message and exits with the
 * appropriate exit status
 * @msg: - Char pointer for error message to be printed
 * @file: Char pointer for file name that can't be opened
 * @status: Int for proper status code to exit with
 * Return: Void
 */

void err_msg(char *msg, char *file, int status)
{
	dprintf(STDIN_FILENO, "%s%s\n", msg, file);
	exit(status);
}
