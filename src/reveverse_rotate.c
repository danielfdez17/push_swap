

#include "../inc/headers/push_swap.h"

int reverse_rotate(t_list *list)
{
	t_list *last;

	printf("Reversing rotate list\n");
	if (!list)
		return (0);
	last = list_last(list);
	while (last && last->previous)
	{
		swap_values(&last->value, &last->previous->value);
		last = last->previous;
	}
	return (1);
}

int rrr(t_list *a, t_list *b)
{
	return (reverse_rotate(a) + reverse_rotate(b));
}