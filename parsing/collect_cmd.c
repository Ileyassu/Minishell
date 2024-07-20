/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:21:38 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/20 17:56:22 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parse_node	*collect_cmd(t_lexer *lexer)
{
	t_cmd			*elem;
	t_parse_node	*node;
	t_rdr_node		*rdrlst;
	t_token			token;

	elem = NULL;
	rdrlst = NULL;
	token = get_token(lexer);
	if (token.type != ERROR && token.type != PIPE
		&& token.type != END && token.type != ENDF)
	{
		if (token.type == VAR)
			free(token.pos);
		if (token.type == WLDC)
			wc_clear(&token.wildcard);
		elem = cmd_components(lexer, &rdrlst);
	}
	if ((elem || rdrlst) && rdrlst != MISSMATCH)
		node = node_create(&elem, rdrlst, CMD);
	else
	{
		cmd_clear(&elem);
		return (MISSMATCH);
	}
	return (node);
}
