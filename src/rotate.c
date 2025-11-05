

#include "../inc/headers/push_swap.h"


// static int rotate(t_stack **list)
// {
// 	t_stack	*last;
// 	t_stack *first;

// 	if (!*list || !(*list)->next)
// 		return (0);
// 	first = *list;
// 	last = stack_last(*list);
// 	*list = first->next;
// 	(*list)->previous = NULL;
// 	last->next = first;
// 	first->previous = last;
// 	first->next = NULL;
// 	return (1);
// }

static int rotate(t_stack **stack)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return (0);
	first = pop_front(stack);
	push_back(stack, first);
	return (1);
}

int		ra(t_stack **a, t_bool print)
{
	int	movs;

	movs = rotate(a);
	if (movs && print)
		ft_printf("ra\n");
	return (movs);
}
// int		rb(t_stack **b, t_bool print)
// {
// 	int	movs;

// 	movs = rotate(b);
// 	if (movs && print)
// 		ft_printf("rb\n");
// 	return (movs);
// }

// int	rr(t_stack **a, t_stack **b, t_bool print)
// {
// 	int	movs;

// 	movs = ra(a, 0) + rb(b, 0);
// 	if (movs > 0 && print)
// 		ft_printf("rr\n");
// 	return (movs);
// }