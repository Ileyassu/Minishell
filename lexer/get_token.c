/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:11:03 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 21:11:04 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/parser.h"
#include <stdlib.h>

t_token	get_token(t_lexer *lexer)
{
	t_token	token;

	while (lexer->str && *lexer->str == 32)
		lexer->str++;
	if (lexer->str[0] == '\0')
		return (t_init(END, 0, NULL));
	if (!ft_strncmp(lexer->str, "|", 1))
	{
		if (lexer->prev_type.type == PIPE || lexer->prev_type.type == CHAR_NULL)
		{
			print_error(t_init(ERROR, 0, NULL));
			return (t_init(ERROR, 0, NULL));
		}
		return (t_init(PIPE, 1, lexer->str));
	}
	if (!ft_strncmp(lexer->str, "<<", 2))
		return (t_init(HERDOC, 2, lexer->str));
	if (!ft_strncmp(lexer->str, ">>", 2))
		return (t_init(RD_APP, 2, lexer->str));
	if (!ft_strncmp(lexer->str, "<", 1))
		return (t_init(RD_IN, 1, lexer->str));
	if (!ft_strncmp(lexer->str, ">", 1))
		return (t_init(RD_OUT, 1, lexer->str));
	token = word_collect(lexer, 0, 0);
	return (token);
}
