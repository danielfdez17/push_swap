

#include "../inc/headers/push_swap.h"

static int	is_asc_sorted(t_list *list)
{
	while (list && list->next)
	{
		if (list >= list->next)
			return (-1);
		list = list->next;
	}
	return (1);
}

static int	is_desc_sorted(t_list *list)
{
	while (list && list->next)
	{
		if (list <= list->next)
			return (-1);
		list = list->next;
	}
	return (1);
}

static t_value	get_min_value(t_list *list)
{
	t_value	min_value;

	min_value.from_begin = 0;
	min_value.from_begin = 0;
	min_value.value = list->value;
	list = list->next;
	while (list)
	{
		if (list->value < min_value.value)
			min_value.value = list->value;
		list = list->next;
	}
	return (min_value);
}

int	selection_sort(t_list *a, t_list *b)
{
	int	movs;

	movs = 1;
	return (movs);
}