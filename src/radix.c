

#include "../inc/headers/push_swap.h"

t_stack	*assign_indexes(t_stack *a)
{
	t_stack	*ptr;
	t_stack	*a_copy;
	t_stack	*b_aux;
	int	i;

	b_aux = NULL;
	a_copy = copy_list(a);
	turk_sort(&a_copy, &b_aux, 0);
	// selection_sort(a_copy, b_aux, 0);
	// counting_sort(&a_copy, &b_aux);
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

int	radix_sort(t_stack **a, t_stack **b, int size, t_bool print)
{
	int	max_bits;
	int	max_num;
	int	movs;

	movs = 0;
	max_bits = 0;
	max_num = size - 1;
	*a = assign_indexes(*a);
	// t_limits lim = ft_get_limits(*a);
	// if (lim.min < 0)
	// 	clean_stack(a, lim.min);
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
				movs += pb(a, b, print);
			else
				movs += ra(a, print);
			++j;
		}
		while (*b)
			movs += pa(a, b, print);
		++i;
	}
	return (movs);
}