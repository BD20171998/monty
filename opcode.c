#include "holberton.h"

/**
 * pall - print all elements of the stack
 * @stack: the stack of elements
 * @line_num: line number
 */
void pall(stack_t **stack, unsigned int line_num)
{
        stack_t *full_stack;
	(void)line_num;

        if (*stack == NULL)
                return;
        full_stack = *stack;
        while (full_stack != NULL)
        {
                printf("%d\n", full_stack->n);
                full_stack = full_stack->next;
        }
}

#include "holberton.h"

/**
 * pint - print the top element of the stack
 * @stack: stack of elements
 * @line_num: line number
 */
void pint(stack_t **stack, unsigned int line_num)
{
        if (stack == NULL)
        {
                printf("L%u: can't pint, stack empty\n", line_num);
                exit(EXIT_FAILURE);
        }
        else
                printf("%d\n", (*stack)->n);

}
