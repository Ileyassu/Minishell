/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:20:47 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/19 20:25:56 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node	*check_pipe(t_lexer *lexer)
{
	t_parser_node	*pipe_line;
	t_parser_node	*pipe;

	if (lexer->curent_type.type == PIPE)
	{
		pipe_line = ft_pipe_line(lexer);
		if (!pipe_line || pipe_line == MISSMATCH)
		{
			ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
			return (NULL);
		}
		else
		{
			pipe = node_create(NULL, NULL, PIPE);
			pipe->right = pipe_line;
			if (pipe)
				return (pipe);
		}
		return (pipe_line);
	}
	else
		return (MISSMATCH);
}
