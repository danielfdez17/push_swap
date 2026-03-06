/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 08:55:17 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:43:14 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bucket_sort(t_stack *a, t_stack *b, bool print)
{
	int		chunck_size;
	int		range;

	set_indexes(a);
	chunck_size = DEFAULT_CHUNK_SIZE;
	if (a->size <= 100)
		chunck_size /= 2;
	range = 0;
	while (!is_stack_empty(a))
	{
		if (a->top->index <= range)
		{
			pb(a, b, print);
			rb(b, print);
			range++;
		}
		else if (a->top->index <= range + chunck_size)
		{
			pb(a, b, print);
			range++;
		}
		else
			ra(a, print);
	}
	push_max_to_b(a, b, print);
}
