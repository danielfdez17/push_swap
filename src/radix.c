

#include "../inc/headers/push_swap.h"

static void	radix_aux(t_stack **a, t_stack **b, int size)
{
	int	max_bits;
	int	max_num;
	int	i;
	int	j;
	int	value;

	max_bits = 0;
	max_num = size - 1;
	while (max_num >> max_bits)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			value = (*a)->value;
			if (((value >> i) & 1) == 0)
				pb(a, b, false);
			else
				ra(a, false);
			++j;
		}
		while (*b)
			pa(a, b, false);
		++i;
	}
}

static t_stack	*assign_indexes(t_stack *a)
{
	t_stack	*ptr;
	t_stack	*a_copy;
	t_stack	*b_aux;
	int	i;

	b_aux = NULL;
	a_copy = copy_list(a);
	radix_aux(&a_copy, &b_aux, get_size(a));
	ptr = a;
	while (ptr)
	{
		i = 0;
		b_aux = a_copy;
		while (b_aux)
		{
			if (b_aux->value == ptr->value)
			{
				ptr->index = i;
				break ;
			}
			b_aux = b_aux->next;
			++i;
		}
		ptr = ptr->next;
	}
	free_stack(a_copy);
	return (a);
}

void	radix_sort(t_stack **a, t_stack **b, int size, t_bool print)
{
	int	max_bits;
	int	max_num;
	int	i;
	int	j;
	int	index;

	max_bits = 0;
	max_num = size - 1;
	*a = assign_indexes(*a);
	while (max_num >> max_bits)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			index = (*a)->index;
			if (((index >> i) & 1) == 0)
				pb(a, b, print);
			else
				ra(a, print);
			++j;
		}
		while (*b)
			pa(a, b, print);
		++i;
	}
}