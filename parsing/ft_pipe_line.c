/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:21:22 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/19 20:25:56 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node	*ft_pipe_line(t_lexer *lexer)
{
	t_parser_node	*cmd;
	t_parser_node	*pipe;

	cmd = collect_cmd(lexer);
	if (cmd && cmd != MISSMATCH)
	{
		pipe = check_pipe(lexer);
		if (pipe == MISSMATCH)
			return (cmd);
		if (pipe)
			pipe->left = cmd;
		else
			node_del(&cmd);
		return (pipe);
	}
	return (cmd);
}
