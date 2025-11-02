

#include "../inc/headers/push_swap.h"


void	swap_values(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	swap(t_stack *list)
{
	// ft_printf("Swapping values\n");
	if (!list || !list->next)
		return (0);
	swap_values(&list->value, &list->next->value);
	return (1);
}

int	sa(t_stack **a, t_bool print)
{
	int	movs;

	movs = swap(*a);
	if (movs && print)
		ft_printf("sa\n");
	return (movs);
}

int	sb(t_stack **b, t_bool print)
{
	int	movs;

	movs = swap(*b);
	if (movs && print)
		ft_printf("sb\n");
	return (swap(*b));
}

int	ss(t_stack **a, t_stack **b, t_bool print)
{
	int	movs;

	movs = sa(a, 0) + sb(b, 0);
	if (movs > 0 && print)
		ft_printf("ss\n");
	return (movs);
}