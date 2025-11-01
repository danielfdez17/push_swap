

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
	ft_printf("Swapping values\n");
	if (!list || !list->next)
		return (0);
	swap_values(&list->value, &list->next->value);
	return (1);
}

int	sa(t_stack **a)
{
	ft_printf("sa\n");
	return (swap(*a));
}

int	sb(t_stack **b)
{
	ft_printf("sb\n");
	return (swap(*b));
}

int	ss(t_stack **a, t_stack **b)
{
	return (sa(a) + sb(b));
}