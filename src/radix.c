

#include "../inc/headers/push_swap.h"

// static t_stack	*assign_indexes(t_stack *a)
// {
// 	t_stack	*ptr;
// 	t_stack	*a_copy;
// 	t_stack	*b_aux;
// 	int	i;

// 	b_aux = NULL;
// 	a_copy = copy_stack(a);
// 	radix_aux(&a_copy, &b_aux, get_size(a));
// 	ptr = a;
// 	while (ptr)
// 	{
// 		i = 0;
// 		b_aux = a_copy;
// 		while (b_aux)
// 		{
// 			if (b_aux->value == ptr->value)
// 			{
// 				ptr->index = i;
// 				break ;
// 			}
// 			b_aux = b_aux->next;
// 			++i;
// 		}
// 		ptr = ptr->next;
// 	}
// 	free_stack(a_copy);
// 	return (a);
// }

static t_stack	*set_indexes(t_stack *stack)
{
	int	*sorted;
	int	size;
	int	i;
	t_stack	*ptr;

	i = 0;
	size = get_size(stack);
	sorted = counting_sort(stack);
	// ft_printf("\n");
	// for (int j = 0; j < size; ++j)
	// 	ft_printf("%d ", sorted[j]);
	// ft_printf("\n");
	while (i < size)
	{
		ptr = stack;
		while (ptr)
		{
			if (ptr->value == sorted[i])
			{
				ptr->index = i;
				break ;
			}
			ptr = ptr->next;
		}
		++i;
	}
	free(sorted);
	return (stack);
}

// void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		ft_printf("(%d,%d)", stack->index, stack->value);
// 		stack = stack->next;
// 	}
// }

void	radix_sort(t_stack **a, t_stack **b, int size, t_bool print)
{
	int	max_bits;
	int	max_num;
	int	i;
	int	j;
	int	index;

	max_bits = 0;
	max_num = size - 1;
	// *a = assign_indexes(*a);
	*a = set_indexes(*a);
	// print_stack(*a);
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