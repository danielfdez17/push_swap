

#include "../inc/headers/push_swap.h"


static int rotate(t_list *list, char stack)
{
	t_list	*ptr;

	(void)stack;
	if (!list)
		return (0);
	// printf("Rotating list %c\n", stack);
	// printf("before: ");
	// print_list(list, stack);
	ptr = list;
	while (ptr && ptr->next)
	{
		swap_values(&ptr->value, &ptr->next->value);
		ptr = ptr->next;
	}
	// printf("after: ");
	// print_list(list, stack);
	return (1);
}

int	rr(t_list **a, t_list **b)
{
	return (ra(a) + rb(b));
}

int		ra(t_list **a)
{
	printf("ra\n");
	return (rotate(*a, A));
}
int		rb(t_list **b)
{
	printf("rb\n");
	return (rotate(*b, B));
}