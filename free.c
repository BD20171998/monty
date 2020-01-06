#include "monty.h"

/**
 * free_all - function that frees all malloc'd memory used and closes the file
 * descriptor
 * Return: Void
 */

void free_all(void)
{
	free(buf.line);
	free(buf.linecopy);
	free_dlistint(*buf.stack);
	fclose(buf.fd);
}

/**
 * free_line - function that frees line buffers used when reading the input and
 * resets the values to NULL afterward
 * Return: Void
 */

void free_line(void)
{
	free(buf.line);
	free(buf.linecopy);
	buf.line = buf.linecopy = NULL;
}

/**
 * free_line2 - function that frees line buffer used when reading the input and
 * closes the file descriptor
 * Return: Void
 */

void free_line2(void)
{
	free(buf.line);
	free_dlistint(*buf.stack);
	fclose(buf.fd);
}
