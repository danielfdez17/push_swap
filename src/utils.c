/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:28:02 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:34:19 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*get_min_value(t_stack *stack)
{
	t_elem	*min_value;
	t_elem	*ptr;

	min_value = stack_get_min(stack);
	ptr = stack->top;
	ptr->position = 0;
	while (ptr->value != min_value->value)
	{
		ptr->position++;
		ptr = ptr->next;
	}
	min_value->position = ptr->position;
	min_value->front = min_value->position;
	min_value->back = stack->size - min_value->position;
	return (min_value);
}

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
