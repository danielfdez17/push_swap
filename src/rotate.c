

#include "../inc/headers/push_swap.h"


static int rotate(t_stack *list)
{
	t_stack	*ptr;

	if (!list)
		return (0);
	ptr = list;
	while (ptr && ptr->next)
	{
		swap_values(&ptr->value, &ptr->next->value);
		ptr = ptr->next;
	}
	return (1);
}

int	rr(t_stack **a, t_stack **b, t_bool print)
{
	int	movs;

	movs = ra(a, 0) + rb(b, 0);
	if (movs > 0 && print)
		ft_printf("rr\n");
	return (movs);
}

int		ra(t_stack **a, t_bool print)
{
	int	movs;

	movs = rotate(*a);
	if (movs && print)
		ft_printf("ra\n");
	return (movs);
}
int		rb(t_stack **b, t_bool print)
{
	int	movs;

	movs = rotate(*b);
	if (movs && print)
		ft_printf("rb\n");
	return (movs);
}