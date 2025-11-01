

#include "../inc/headers/push_swap.h"


static int rotate(t_stack *list, char stack)
{
	t_stack	*ptr;

	(void)stack;
	if (!list)
		return (0);
	// ft_printf("Rotating list %c\n", stack);
	// ft_printf("before: ");
	// print_list(list, stack);
	ptr = list;
	while (ptr && ptr->next)
	{
		swap_values(&ptr->value, &ptr->next->value);
		ptr = ptr->next;
	}
	// ft_printf("after: ");
	// print_list(list, stack);
	return (1);
}

int	rr(t_stack **a, t_stack **b)
{
	return (ra(a) + rb(b));
}

int		ra(t_stack **a)
{
	ft_printf("ra\n");
	return (rotate(*a, A));
}
int		rb(t_stack **b)
{
	ft_printf("rb\n");
	return (rotate(*b, B));
}