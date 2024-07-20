/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:49:49 by mel-hous          #+#    #+#             */
/*   Updated: 2024/07/20 15:04:13 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"

char	*quote_def(char	*str)
{
	char	*s;
	int		mode;

	s = str;
	mode = 0;
	while (*s)							//mode = 1
	{                                //-1"fsdfsdfsdf"-1
		mode = change_mode(mode, *s);
		if (*s == 34 && (mode == 2 || mode == 0))
			*s = DEF_DOUBEL_Q;
		else if (*s == 39 && (mode == 1 || mode == 0))
			*s = DEF_SINGEL_Q;
		s++;
	}
	return (str);
}
