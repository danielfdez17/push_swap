/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reveverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:32 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:47:24 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack *stack)
{
	t_elem	*last;

	last = pop_bottom(stack);
	if (!last)
		return (0);
	push_top(stack, last);
	return (1);
}

int	rra(t_stack *a, bool print)
{
	int	movs;

	movs = reverse_rotate(a);
	if (movs && print)
		ft_printf("rra\n");
	return (movs);
}

int	rrb(t_stack *b, bool print)
{
	int	movs;

	movs = reverse_rotate(b);
	if (movs && print)
		ft_printf("rrb\n");
	return (movs);
}

int	rrr(t_stack *a, t_stack *b, bool print)
{
	int	movs;

	movs = rra(a, 0) + rrb(b, 0);
	if (movs > 0 && print)
		ft_printf("rrr\n");
	return (movs);
}
