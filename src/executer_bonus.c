#include "push_swap.h"

bool	execute_move(t_stack *a, t_stack *b, char *move)
{
	if (ft_strncmp(move, "sa\n", 4) == 0)
		sa(a, false);
	else if (ft_strncmp(move, "sb\n", 4) == 0)
		sb(b, false);
	else if (ft_strncmp(move, "ss\n", 4) == 0)
		ss(a, b, false);
	else if (ft_strncmp(move, "pa\n", 4) == 0)
		pa(a, b, false);
	else if (ft_strncmp(move, "pb\n", 4) == 0)
		pb(a, b, false);
	else if (ft_strncmp(move, "ra\n", 4) == 0)
		ra(a, false);
	else if (ft_strncmp(move, "rb\n", 4) == 0)
		rb(b, false);
	else if (ft_strncmp(move, "rr\n", 4) == 0)
		rr(a, b, false);
	else if (ft_strncmp(move, "rra\n", 5) == 0)
		rra(a, false);
	else if (ft_strncmp(move, "rrb\n", 5) == 0)
		rrb(b, false);
	else if (ft_strncmp(move, "rrr\n", 5) == 0)
		rrr(a, b, false);
	else
		return (false);
	return (true);
}
