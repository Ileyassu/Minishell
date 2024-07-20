/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:22:12 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/20 18:28:10 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parse_node	*parse_input(t_lexer *lexer)
{
	t_parse_node	*pipeline;
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
