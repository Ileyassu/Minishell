/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:54:48 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/20 18:54:50 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	*lex_init(char *s)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	lexer->full_str = s;
	lexer->str = s;
	lexer->prev_type = t_init(CHAR_NULL, 0, NULL);
	lexer->curent_type = t_init(CHAR_NULL, 0, NULL);
	return (lexer);
}

t_token	t_init(t_token_type	_tp, int len, char *p)
{
	t_token	tok;

	tok.type = _tp;
	tok.pos = p;
	tok.len = len;
	tok.wildcard = NULL;
	return (tok);
}

t_token	t_wc_init(t_token_type	type, int len, t_wc_node *p, char *pos)
{
	t_token	tok;

	tok.type = type;
	tok.pos = pos;
	tok.len = len;
	tok.wildcard = p;
	return (tok);
}
