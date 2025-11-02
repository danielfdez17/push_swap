

#include "../inc/headers/push_swap.h"

static int reverse_rotate(t_stack **list)
{
	t_stack *last;

	if (!*list)
		return (0);
	last = stack_last(*list);
	last->previous->next = NULL;
	last->next = *list;
	last->previous = NULL;
	*list = last;
	last->next->previous = last;
	return (1);
}

int	rrr(t_stack **a, t_stack **b, t_bool print)
{
	int movs;

	movs = rra(a, 0) + rrb(b, 0);
	if (movs > 0 && print)
		ft_printf("rrr\n");
	return (movs);
}

int		rra(t_stack **a, t_bool print)
{
	int	movs;

	movs = reverse_rotate(a);
	if (movs && print)
		ft_printf("rra\n");
	return (movs);
}
int		rrb(t_stack **b, t_bool print)
{
	int movs;

	movs = reverse_rotate(b);
	if (movs && print)
		ft_printf("rrb\n");
	return (movs);
}