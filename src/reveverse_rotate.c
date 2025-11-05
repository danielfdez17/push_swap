

#include "../inc/headers/push_swap.h"

// static int reverse_rotate(t_stack **stack)
// {
// 	t_stack *last;

// 	if (!*stack)
// 		return (0);
// 	last = stack_last(*stack);
// 	if (last == *stack) // Only one element in the stack
// 		return (0);
// 	last->previous->next = NULL;
// 	last->next = *stack;
// 	last->previous = NULL;
// 	*stack = last;
// 	if (last->next)
// 		last->next->previous = last;
// 	return (1);
// }

static int reverse_rotate(t_stack **stack)
{
	t_stack *last;

	last = pop_back(stack);
	if (!last)
		return (0);
	push_front(stack, last);
	return (1);
}

int		rra(t_stack **a, t_bool print)
{
	int	movs;

	movs = reverse_rotate(a);
	if (movs && print)
		ft_printf("rra\n");
	return (movs);
}
// int		rrb(t_stack **b, t_bool print)
// {
// 	int movs;

// 	movs = reverse_rotate(b);
// 	if (movs && print)
// 		ft_printf("rrb\n");
// 	return (movs);
// }

// int	rrr(t_stack **a, t_stack **b, t_bool print)
// {
// 	int movs;

// 	movs = rra(a, 0) + rrb(b, 0);
// 	if (movs > 0 && print)
// 		ft_printf("rrr\n");
// 	return (movs);
// }