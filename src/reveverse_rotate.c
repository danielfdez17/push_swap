

#include "../inc/headers/push_swap.h"

int reverse_rotate(t_list *list, char stack)
{
	t_list *last;

	(void)stack;
	if (!list)
		return (0);
	// printf("Reverse rotating list %c\n", stack);
	// printf("before: ");
	// print_list(list, stack);
	last = list_last(list);
	while (last && last->previous)
	{
		swap_values(&last->value, &last->previous->value);
		last = last->previous;
	}
	// printf("after: ");
	// print_list(list, stack);
	return (1);
}

int rrr(t_list *a, t_list *b)
{
	return (reverse_rotate(a, A) + reverse_rotate(b, B));
}