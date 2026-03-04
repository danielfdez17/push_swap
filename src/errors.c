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
 * Checks if the string @param s contains syntax errors.
 * If no error are found, @returns false. Otherwise @returns true
 */
bool	input_error(char *s)
{
	int	i;

	i = 0;
	if (!is_valid_char(s[i]))
		return (true);
	if (ft_is_sign(s[i++]) && !ft_isdigit(s[i]))
		return (true);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (true);
		++i;
	}
	if (!ft_is_integer(s))
		return (true);
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
	free_stack(stack);
	ft_printf("Error\n");
	return (false);
}
