/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:47:28 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:47:29 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
