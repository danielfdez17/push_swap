

#include "../inc/headers/push_swap.h"

static int	is_asc_sorted(t_list *list)
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

static int	is_desc_sorted(t_list *list)
{
	if (!list || !list->next)
		return (1);
	while (list && list->next)
	{
		if (list->value <= list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

static t_value	get_min_value(t_list *list)
{
	t_value	min_value;
	t_list	*ptr;

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

int	selection_sort(t_list *a, t_list *b)
{
	int	movs;
	int	asc_a;
	int desc_b;
	t_value value;

	movs = 0;
	asc_a = 0;
	desc_b = 0;
	while (!asc_a || !desc_b)
	{
		if (a)
		{
			value = get_min_value(a);
			while (a->value != value.value)
			{
				if (value.front <= value.back)
				movs += ra(&a);
				else
				movs += rra(&a);
			}
			movs += pb(&a, &b);
		}
		// print_list(a, A);
		// print_list(b, B);
		// sleep(1);
		asc_a = is_asc_sorted(a);
		desc_b = is_desc_sorted(b);
	}
	while (b)
		movs += pa(&a, &b);
	// printf("front: %d, value: %d, behind: %d\n", value.front, value.value, value.back);
	return (movs);
}