/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:24 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 07:44:48 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @returns the minimum value of the @param stack 
 * with its distance to both first and last element of @param stack
 */
static t_value	get_min_value(t_stack *stack)
{
	t_value	min_value;
	t_stack	*ptr;

	min_value.front = 0;
	min_value.back = 0;
	ptr = stack;
	min_value.value = ptr->value;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->value < min_value.value)
			min_value.value = ptr->value;
		ptr = ptr->next;
		min_value.back++;
	}
	ptr = stack;
	while (ptr->value != min_value.value)
	{
		min_value.front++;
		min_value.back--;
		ptr = ptr->next;
	}
	return (min_value);
}

/**
 * Selection sorting algorithm
 */
void	selection_sort(t_stack **a, t_stack **b, bool print)
{
	t_value	value;

	while (!is_stack_sorted(*a))
	{
		if (*a)
		{
			value = get_min_value(*a);
			if (value.front == 1)
			{
				sa(a, print);
				continue ;
			}
			while ((*a)->value != value.value)
			{
				if (value.front <= value.back)
					ra(a, print);
				else
					rra(a, print);
			}
			pb(a, b, print);
		}
	}
	while (*b)
		pa(a, b, print);
}
