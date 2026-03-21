/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:52 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:23:35 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_aux(int *i, int *max_bits, int size)
{
	int	max_num;

	max_num = size - 1;
	*max_bits = 0;
	*i = -1;
	while (max_num >> *max_bits)
		++(*max_bits);
}

void	sort_algorithm(t_stack *a, t_stack *b, bool print)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	size = stack_size(a);
	set_indexes(a);
	radix_aux(&i, &max_bits, size);
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b, print);
			else
				ra(a, print);
		}
		while (!is_stack_empty(b))
			pa(a, b, print);
	}
}
