

#include "../inc/headers/push_swap.h"

t_stack	*assign_indexes(t_stack *a, int size)
{
	t_stack	*ptr;
	t_stack	*copy;
	t_stack	*ptr_copy;
	int	i;

	(void)size;
	ptr_copy = NULL;
	copy = copy_list(a);
	selection_sort(copy, ptr_copy);

	ptr = a;
	while (ptr)
	{
		i = 0;
		ptr_copy = copy;
		while (ptr_copy)
		{
			if (ptr_copy->value == ptr->value)
			{
				ptr->index = i;
				break ;
			}
			ptr_copy = ptr_copy->next;
			++i;
		}
		ptr = ptr->next;
	}
	// print_list(a, 'a');
	// print_list(copy, 'c');
	free_list(copy);
	return (a);
}

int	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	max_bits;
	int	max_num;
	int	movs;

	movs = 0;
	max_bits = 0;
	max_num = size - 1;
	*a = assign_indexes(*a, size);
	while (max_num >> max_bits)
		++max_bits;
	int i = 0;
	int j = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			int num = (*a)->index;
			if (((num >> i) & 1) == 0)
				movs += pb(a, b);
			else
				movs += ra(a);
			++j;
		}
		while (*b)
			movs += pa(a, b);
		++i;
	}
	// print_list(copy, 'i');
	return (movs);
}