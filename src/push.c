

#include "../inc/headers/push_swap.h"

int	push(t_list **a, t_list **b)
{
	if (!*b)
		return (0);
	push_front(a, (*b));
	pop_front(b);
	return (1);
}