/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:22:12 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/19 20:25:56 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node	*parse_input(t_lexer *lexer)
{
	t_parser_node	*pipeline;
	t_token			token;

	pipeline = ft_pipe_line(lexer);
	if (!pipeline || pipeline == MISSMATCH)
		return (pipeline);
	token = get_next_token(lexer);
	if (token.type != END)
	{
		print_error(token);
		node_del(&pipeline);
		return (NULL);
	}
	return (pipeline);
}
