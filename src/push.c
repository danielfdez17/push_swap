

#include "../inc/headers/push_swap.h"

int	pa(t_stack **a, t_stack **b, t_bool print)
{
	t_stack	*elem;

	if (!*b)
		return (0);
	elem = pop_front(b);
	push_front(a, elem);
	if (print)
		ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **a, t_stack **b, t_bool print)
{
	t_stack	*elem;

	if (!*a)
		return (0);
	elem = pop_front(a);
	push_front(b, elem);
	if (print)
		ft_printf("pb\n");
	return (1);
}