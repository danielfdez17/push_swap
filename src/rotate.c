

#include "../inc/headers/push_swap.h"


int rotate(t_list *list)
{
	if (!list)
		return (0);
	while (list && list->next)
	{
		swap_values(&list->value, &list->next->value);
		list = list->next;
	}
	return (1);
}

int	rr(t_list *a, t_list *b)
{
	return (rotate(a) + rotate(b));
}