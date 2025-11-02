

#include "../inc/headers/push_swap.h"

void	set_indexes(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = get_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*ptr;
	t_stack	*target;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		ptr = b;
		while (ptr)
		{
			if (ptr->value < a->value && ptr->value > best_match_index)
			{
				best_match_index = ptr->value;
				target = ptr;
			}
			ptr = ptr->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = get_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	set_a_cost_analysis(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = get_size(a);
	size_b = get_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = size_a - a->index;
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += size_b - a->target->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_a(t_stack *a, t_stack *b)
{
	set_indexes(a);
	set_indexes(b);
	set_target_a(a, b);
	set_a_cost_analysis(a, b);
	set_cheapest(a);
}