

#include "../inc/headers/push_swap.h"

// * 1. Generate counting sort
// * 2. For every element, have a structure that indicates if it's better to do a rotate or a reverse_rotate
// * 3. Push every element from a to b to achieve ascending order

t_limits	ft_get_limits(t_stack *a)
{
	t_limits	lim;

	lim.max = LONG_MIN;
	lim.min = LONG_MAX;
	while (a)
	{
		if (a->value > lim.max)
			lim.max = a->value;
		else if (a->value < lim.min)
			lim.min = a->value;
		a = a->next;
	}
	return (lim);
}

void	update_median(t_stack **a)
{
	t_stack	*ptr;
	int	median;

	median = get_size(*a) / 2;
	ptr = *a;
	while (ptr)
	{
		if (ptr->value <= median)
			ptr->above_median = false;
		else
			ptr->above_median = true;
		ptr = ptr->next;
	}
}

void	clean_stack(t_stack **a, long min_value)
{
	t_stack	*ptr;

	ptr = *a;
	while (ptr)
	{
		ptr->value += min_value;
		ptr = ptr->next;
	}
}

void	fill_count_array(int *count_array, t_stack *a)
{
	while (a)
	{
		count_array[a->value]++;
		a = a->next;
	}
}

void	accumulate(int **count_array, int size)
{
	int	i;
	int	*ptr;

	i = 1;
	ptr = *count_array;
	while (i < size)
	{
		ptr[i] += ptr[i - 1];
		++i;
	}
}

t_bool	put_first(t_stack **a, int value)
{
	t_stack	*elem;

	elem = *a;
	while (elem && elem->value != value)
		elem = elem->next;
	if (!elem)
		return (false);
	while (*a != elem)
	{
		if (elem->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
	return (true);
}

void	sort(t_stack **a, t_stack **b, int *count_array, long size)
{
	long i;

	(void)count_array;
	i = size;
	while (i--)
	{
		if (put_first(a, i))
			pb(a, b, true);
	}
}

void	counting_sort(t_stack **a, t_stack **b)
{
	t_limits	lim;
	int		*count_array;

	lim = ft_get_limits(*a);
	count_array = malloc(sizeof(int) * (lim.max - lim.min + 1));
	if (!count_array)
		return ;
	ft_bzero(count_array, lim.max - lim.min + 1);
	update_median(a);
	if (lim.min < 0)
		clean_stack(a, -lim.min);
	fill_count_array(count_array, *a);
	accumulate(&count_array, lim.max - lim.min + 1);
	// ft_printf("min: %d, max: %d\n", lim.min, lim.max);
	// for (int i = 0; i < lim.max - lim.min + 1; ++i)
	// 	ft_printf("%d ", count_array[i]);
	// ft_printf("\n");
	sort(a, b, count_array, lim.max - lim.min + 1);
	// print_list(*a);
	// clean_stack(b, lim.min);
	// print_list(*b);
	free(count_array);
}