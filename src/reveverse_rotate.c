

#include "../inc/headers/push_swap.h"

static int reverse_rotate(t_stack *list, char stack)
{
	t_stack *last;

	(void)stack;
	if (!list)
		return (0);
	// ft_printf("Reverse rotating list %c\n", stack);
	// ft_printf("before: ");
	// print_list(list, stack);
	last = list_last(list);
	while (last && last->previous)
	{
		swap_values(&last->value, &last->previous->value);
		last = last->previous;
	}
	// ft_printf("after: ");
	// print_list(list, stack);
	return (1);
}

int	rrr(t_stack **a, t_stack **b)
{
	return (rra(a) + rrb(b));
}

int		rra(t_stack **a)
{
	ft_printf("rra\n");
	return (reverse_rotate(*a, A));
}
int		rrb(t_stack **b)
{
	ft_printf("rrb\n");
	return (reverse_rotate(*b, B));
}