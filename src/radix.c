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

void	set_indexes(t_stack *stack)
{
	int		*sorted;
	int		i;
	t_elem	*ptr;

	i = 0;
	sorted = counting_sort(stack);
	while (i < stack->size)
	{
		ptr = stack->top;
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
}
