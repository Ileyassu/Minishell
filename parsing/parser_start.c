/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:07:26 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 21:41:05 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node	*parse(char *input)
{
	t_parser_node	*ast;
	t_lexer			*lexer;

	lexer = lex_init(quote_def(input));
	ast = parse_input(lexer);
	if (!ast || ast == (void *)-1)
	{
		g_lbv.exit_status = 258 * 256;
		free(lexer);
		return (NULL);
	}
	free(lexer);
	return (ast);
}
