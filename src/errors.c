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

#include "../inc/headers/push_swap.h"

/**
 * @returns TRUE if @param c is either + or -. Otherwise @returns FALSE
 */
static t_bool	is_plus_minus(char c)
{
	return (c == '+' || c == '-');
}

/**
 * Checks if the string @param s contains syntax errors.
 * If no error are found, @returns FALSE. Otherwise @returns TRUE
 */
t_bool	syntax_error(char *s)
{
	int	i;

	i = 0;
	if (!(is_plus_minus(s[i]) || ft_isdigit(s[i])))
		return (TRUE);
	if (is_plus_minus(s[i++]) && !ft_isdigit(s[i]))
		return (TRUE);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (TRUE);
		++i;
	}
	return (FALSE);
}

/**
 * Checks if the value of @param n is already stored in the @param stack.
 * If so, @returns TRUE. Otherwisre @returns FALSE
 */
t_bool	duplicate_error(t_stack *stack, int n)
{
	if (!stack)
		return (FALSE);
	while (stack)
	{
		if (stack->value == n)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}

/**
 * It frees the @param stack, prints the string "Error\n" and @returns FALSE 
 * to indicate the @param stack could not have been initialized.
 */
t_bool	free_error(t_stack **stack)
{
	free_stack(*stack);
	ft_printf("Error\n");
	return (FALSE);
}
