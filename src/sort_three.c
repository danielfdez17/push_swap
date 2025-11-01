

#include "../inc/headers/push_swap.h"


void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		ra(a, 0);
	else if ((*a)->next == biggest)
		rra(a, 0);
	if ((*a)->number > (*a)->next->number)
		sa(a, 0);
}