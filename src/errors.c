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
