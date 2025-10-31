

#include "../inc/headers/push_swap.h"

// int	push_from_to(t_list **a, t_list **b)
// {
// 	t_list	*elem;

// 	if (!*a)
// 		return (0);
// 	elem = pop_front(a);
// 	push_front(b, elem);
// 	return (1);
// }

int	pa(t_list **a, t_list **b)
{
	t_list	*elem;

	if (!*b)
		return (0);
	elem = pop_front(b);
	push_front(a, elem);
	printf("pa\n");
	return (1);
}

int	pb(t_list **a, t_list **b)
{
	t_list	*elem;

	if (!*a)
		return (0);
	elem = pop_front(a);
	push_front(b, elem);
	printf("pb\n");
	return (1);
}