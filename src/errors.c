

#include "../inc/headers/push_swap.h"

static	t_bool is_plus_minus(char c)
{
	return (c == '+' || c == '-');
}

t_bool	syntax_error(char *s)
{
	int	i;

	i = 0;
	if (!(is_plus_minus(s[i]) || ft_isdigit(s[i])))
		return (1);
	if (is_plus_minus(s[i++]) && !ft_isdigit(s[i]))
		return (1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		++i;
	}
	return (0);
}

t_bool	duplicate_error(t_stack *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_error(t_stack **stack)
{
	free_stack(*stack);
	ft_printf("Error\n");
	exit(1);
}