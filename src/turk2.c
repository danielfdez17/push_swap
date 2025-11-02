

#include "../inc/headers/push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*max_node;

	max_node = get_max(*stack);
	if (max_node == *stack)
		ra(stack, 1);
	else if ((*stack)->next == max_node)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}