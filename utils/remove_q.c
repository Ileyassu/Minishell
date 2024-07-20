/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_q.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:27:13 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/19 20:27:19 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"

char	*remove_q(char	*str)
{
	char	*s;
	int		n;

	s = str;
	n = ft_strlen(s);
	while (*s)
	{
		if (*s == DEF_SINGEL_Q || *s == DEF_DOUBEL_Q)
			ft_memmove(s, s + 1, n);
		else
			s++;
		n--;
	}
	return (str);
}
