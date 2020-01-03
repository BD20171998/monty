#include "monty.h"

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

/**
 * pint - remove element from stack
 * @stack: stack of elements
 * @line_num: line number
 */
void pop(stack_t **stack, unsigned int line_num)
{
        stack_t *next = NULL;

        if (stack == NULL || *stack == NULL)
        {
                printf("L%u: can't pop an empty stack\n", line_num);
                exit(EXIT_FAILURE);
        }

        next = (*stack)->next;
        free(*stack);
        *stack = next;
        if (*stack == NULL)
                return;
        (*stack)->prev = NULL;
}
