/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 08:55:17 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/20 16:57:28 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	bucket_sort(t_stack *a, t_stack *b, bool print)
void	sort_algorithm(t_stack *a, t_stack *b, bool print)
{
	int		chunk_size;
	int		range;

	set_indexes(a);
	chunk_size = DEFAULT_CHUNK_SIZE;
	if (a->size <= 100)
		chunk_size /= 2;
	range = 0;
	while (!is_stack_empty(a))
	{
		if (a->top->index <= range)
		{
			pb(a, b, print);
			rb(b, print);
			range++;
		}
		else if (a->top->index <= range + chunk_size)
		{
			pb(a, b, print);
			range++;
		}
		else
			ra(a, print);
	}
	push_all_to_a(a, b, print);
}
