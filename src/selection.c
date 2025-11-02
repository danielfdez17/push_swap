

#include "../inc/headers/push_swap.h"

static int	is_asc_sorted(t_stack *list)
{
	if (!list || !list->next)
		return (1);
	while (list && list->next)
	{
		if (list->value >= list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

static t_value	get_min_value(t_stack *list)
{
	t_value	min_value;
	t_stack	*ptr;

	min_value.front = 0;
	min_value.back = 0;
	ptr = list;
	min_value.value = ptr->value;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->value < min_value.value)
			min_value.value = ptr->value;
		ptr = ptr->next;
		min_value.back++;
	}
	ptr = list;
	while (ptr->value != min_value.value)
	{
		min_value.front++;
		min_value.back--;
		ptr = ptr->next;
	}
	return (min_value);
}

int	selection_sort(t_stack *a, t_stack *b)
{
	int	movs;
	t_value value;

	movs = 0;
	while (!is_asc_sorted(a))
	{
		if (a)
		{
			value = get_min_value(a);
			while (a->value != value.value)
			{
				if (value.front <= value.back)
				movs += ra(&a, 0);
				else
				movs += rra(&a, 0);
			}
			movs += pb(&a, &b, 0);
		}
	}
	while (b)
		movs += pa(&a, &b, 0);
	// ft_printf("front: %d, value: %d, behind: %d\n", value.front, value.value, value.back);
	return (movs);
}