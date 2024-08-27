/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:06:46 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 21:37:57 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node	*collect_cmd(t_lexer *lexer)
{
	t_cmd			*elem;
	t_parser_node	*node;
	t_rdr_node		*rdrlst;
	t_token			token;
	void			*ptr;

	ptr = (void *)-1;
	elem = NULL;
	rdrlst = NULL;
	token = get_token(lexer);
	if (token.type != ERROR && token.type != PIPE && token.type != END
		&& token.type != ENDF)
	{
		if (token.type == VAR)
			free(token.pos);
		elem = cmd_ccomponents(lexer, &rdrlst);
	}
	if ((elem || rdrlst) && rdrlst != ptr)
		node = node_create(&elem, rdrlst, CMD);
	else
	{
		cmd_clear(&elem);
		return (ptr);
	}
	return (node);
}
