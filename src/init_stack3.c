

#include "../inc/headers/push_swap.h"

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*ptr;
	t_stack	*target;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		ptr = a;
		while (ptr)
		{
			if (ptr->value > b->value && ptr->value < best_match_index)
			{
				best_match_index = ptr->value;
				target = ptr;
			}
			ptr = ptr->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_b(t_stack *a, t_stack *b)
{
	set_indexes(a);
	set_indexes(b);
	set_target_b(a, b);
}