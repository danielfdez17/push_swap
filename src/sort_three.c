

#include "../inc/headers/push_swap.h"

/**
 * Algorithm to sort only 3 elements
 */
void	sort_three(t_stack **stack, t_bool print)
{
	t_stack	*max_node;

	max_node = get_max(*stack);
	if (max_node == *stack)
		ra(stack, print);
	else if ((*stack)->next == max_node)
		rra(stack, print);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, print);
}