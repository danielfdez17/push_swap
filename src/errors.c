/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:45 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 07:49:51 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @returns true if @param c is either + or -. Otherwise @returns false
 */
static bool	is_plus_minus(char c)
{
	return (c == '+' || c == '-');
}

/**
 * Checks if the string @param s contains syntax errors.
 * If no error are found, @returns false. Otherwise @returns true
 */
bool	syntax_error(char *s)
{
	int	i;

	i = 0;
	if (!(is_plus_minus(s[i]) || ft_isdigit(s[i])))
		return (true);
	if (is_plus_minus(s[i++]) && !ft_isdigit(s[i]))
		return (true);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (true);
		++i;
	}
	return (false);
}

/**
 * Checks if the value of @param n is already stored in the @param stack.
 * If so, @returns true. Otherwisre @returns false
 */
bool	duplicate_error(t_stack *stack, int n)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->value == n)
			return (true);
		stack = stack->next;
	}
	return (false);
}

/**
 * It frees the @param stack, prints the string "Error\n" and @returns false 
 * to indicate the @param stack could not have been initialized.
 */
bool	free_error(t_stack **stack)
{
	free_stack(*stack);
	ft_printf("Error\n");
	return (false);
}
