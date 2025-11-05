
#include "../inc/headers/push_swap.h"

static t_limits	get_limits(t_stack *stack)
{
	t_limits	limits;

	limits.max = stack->value;
	limits.min = stack->value;
	while (stack)
	{
		if (stack->value > limits.max)
			limits.max = stack->value;
		else if (stack->value < limits.min)
			limits.min = stack->value;
		stack = stack->next;
	}
	return (limits);
}

static void	count_occurrences(t_stack *ptr, int *accumulates, t_limits limits)
{
	while (ptr)
	{
		accumulates[ptr->value - limits.min]++;
		ptr = ptr->next;
	}
}

static void accumulate(int *accumulates, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		accumulates[i + 1] += accumulates[i];
		++i;
	}
}

static void	sort_values(t_stack *ptr, int *sorted, int *accumulates, t_limits limits)
{
	while (ptr)
	{
		sorted[accumulates[ptr->value - limits.min] - 1] = ptr->value;
		ptr = ptr->next;
	}
}

int	*counting_sort(t_stack *stack)
{
	int		*accumulates;
	int		*sorted;
	t_limits limits;

	limits = get_limits(stack);
	accumulates = malloc(sizeof(int) * (limits.max - limits.min + 1));
	if (!accumulates)
		return (NULL);
	sorted = malloc(sizeof(int) * get_size(stack));
	if (!sorted)
		return (NULL);
	ft_bzero(accumulates, limits.max - limits.min + 1);
	count_occurrences(stack, accumulates, limits);
	accumulate(accumulates, limits.max - limits.min);
	sort_values(stack, sorted, accumulates, limits);
	free(accumulates);
	return (sorted);
}

