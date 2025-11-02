

#include "../inc/headers/push_swap.h"

static void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest, int which_rotation)
{
	while (*b != cheapest->target && *a != cheapest->target)
	{
		if (which_rotation == RR)
			rr(a, b, 1);
		else if (which_rotation == RRR)
			rrr(a, b, 1);
	}
	set_indexes(*a);
	set_indexes(*b);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest, RR);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rotate_both(a, b, cheapest, RRR);
	prep_for_push(a, cheapest, A);
	prep_for_push(b, cheapest->target, B);
	pb(a, b, 1);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, A);
	pa(a, b, 1);
}

static void	min_on_top(t_stack **stack)
{
	t_stack	*min_node;

	min_node = get_min(*stack);
	while ((*stack)->value != min_node->value)
	{
		if (min_node->above_median)
			ra(stack, 1);
		else
			rra(stack, 1);
		min_node = get_min(*stack);
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = get_size(*a);
	if (size-- > 3 && !is_stack_sorted(*a))
		pb(a, b, 1);
	if (size-- > 3 && !is_stack_sorted(*a))
		pb(a, b, 1);
	while (size-- > 3 && !is_stack_sorted(*a))
	{
		init_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_indexes(*a);
	min_on_top(a);
}