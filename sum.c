#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @stack: head
 * @num_line: number of line
 */
void _add(stack_a **stack, unsigned int num_line)
{
	stack_a *tmp1;
	stack_a *tmp2;
	int tot = 0;

	if (*stack && (*stack)->next)
	{
		tmp2 = (*stack)->next;
		tot = (*stack)->b + tmp2->b;
		tmp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(tmp1);
		(*stack)->b = tot;
	}
	else
	{
		dprintf (2, "L%d: can't add, stack too short\b", num_line);
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}
