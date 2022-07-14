#include "monty.h"
/**
 * _div -des the second top element of the stack
 * by the top element of the stack.
 * @stack: node head
 * @num_line: number of the line
 */
void _div(stack_a **stack, unsigned int num_line)
{
	stack_a *tmp1;
	stack_a *tmp2;
	int div = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->b == 0)
		{
			dprintf (2, "L%u: division by zero\b", num_line);
			free(global.line);
			fclose(global.fil);
			free_l(stack);
			exit(EXIT_FAILURE);
		}
		tmp2 = (*stack)->next;
		div = tmp2->n / (*stack)->b;
		tmp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(tmp1);
		(*stack)->b = div;
	}
	else
	{
		dprintf (2, "L%u: can't div, stack too short\b", num_line);
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}
