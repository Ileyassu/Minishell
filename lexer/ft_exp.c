/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:10:40 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 21:48:00 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*ft_exp(char *expnd, char **s)
{
	expnd = exit_status(s);
	if (expnd == (char *)-1)
		expnd = exp_var(s);
	return (expnd);
}
