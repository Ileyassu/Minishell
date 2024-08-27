/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:06:33 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 21:35:54 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_node	*check_pipe(t_lexer *lexer)
{
	t_parser_node	*pipe_line;
	t_parser_node	*pipe;
	void			*ptr;

	ptr = (void *)-1;
	if (lexer->curent_type.type == PIPE)
	{
		pipe_line = ft_pipe_line(lexer);
		if (!pipe_line || pipe_line == ptr)
		{
			ft_putstr_fd("minishell: syntax error: unexpected end of file\n",
				2);
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
		return (ptr);
}
