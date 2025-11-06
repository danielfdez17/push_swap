

#include "../inc/headers/push_swap.h"

/**
 * @returns true if @param c is either + or -. Otherwise @returns false
 */
static	t_bool is_plus_minus(char c)
{
	return (c == '+' || c == '-');
}

/**
 * Checks if the string @param s contains syntax errors.
 * If no error are found, @returns false. Otherwise @returns true
 */
t_bool	syntax_error(char *s)
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
t_bool	duplicate_error(t_stack *stack, int n)
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
t_bool	free_error(t_stack **stack)
{
	free_stack(*stack);
	ft_printf("Error\n");
	return (false);
}
