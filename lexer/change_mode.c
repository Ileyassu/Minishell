/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:09:15 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 21:09:17 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	change_mode(int i, char c)
{
	if (c == 39)
	{
		if (i == 2)
			return (i);
		if (i == 1)
			return (0);
		return (1);
	}
	if (c == 34)
	{
		if (i == 1)
			return (i);
		if (i == 2)
			return (0);
		return (2);
	}
	return (i);
}

int	change_mode2(int i, char c)
{
	if (c == DEF_SINGEL_Q)
	{
		if (i == 1)
			return (0);
		if (i == 0)
			return (1);
	}
	if (c == DEF_DOUBEL_Q)
	{
		if (i == 2)
			return (0);
		if (i == 0)
			return (2);
	}
	return (i);
}
