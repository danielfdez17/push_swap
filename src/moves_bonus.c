#include "checker_bonus.h"

void	read_moves(t_stack *a, t_stack *b)
{
	char	*move;

	while (true)
	{
		move = get_next_line(STDIN_FILENO);
		if (!move)
			break ;
		if (!execute_move(a, b, move))
		{
			ft_putendl_fd("Error: invalid move", STDERR_FILENO);
			free(move);
			return ;
		}
		free(move);
	}
}
