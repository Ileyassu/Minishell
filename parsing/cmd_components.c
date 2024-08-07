/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:21:15 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/20 17:56:22 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	handle_rdr(t_lexer *lexer, t_rdr_node **rdr, t_token token,
					t_rdr_node *tmp)
{
	tmp = collect_rdr(lexer, *rdr, token);
	if (tmp == MISSMATCH)
	{
		if (rdr)
			rdr_clear(rdr);
		else
			*rdr = MISSMATCH;
	}
	rdr_addback(rdr, tmp);
}

t_cmd	*cmd_components(t_lexer *lexer, t_rdr_node **rdr)
{
	t_token		token;
	t_cmd		*cmd;
	t_rdr_node	*tmp;

	cmd = NULL;
	tmp = NULL;
	token = t_init(CHAR_NULL, 0, NULL);
	while (token.type != END && token.type != ERROR
		&& token.type != PIPE && token.type != TOK
		&& token.type != ENDF && *rdr != MISSMATCH)
	{
		token = get_next_token(lexer);
		if (token.type == WORD)
			cmd_addback(&cmd, ft_new_cmd(ft_substr(token.pos, 0, token.len),
					NULL));
		else if (token.type == VAR)
			cmd_addback(&cmd, ft_new_cmd(token.pos, NULL));
		else if (token.type == WLDC)
			cmd_addback(&cmd, ft_new_cmd(NULL, &token.wildcard));
		else if (token.type == RD_APP || token.type == RD_IN
			|| token.type == RD_OUT || token.type == HERDOC)
			handle_rdr(lexer, rdr, token, tmp);
	}
	return (cmd);
}
