/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:26:49 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/19 20:26:51 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include<string.h>
# include<errno.h>
# include "../parsing/parser.h"
# include "../execution/execution.h"
# include <fcntl.h>

typedef struct s_out_in_file{
	int	input_file;
	int	output_file;
}	t_out_in_file;

void	*rdr_input(t_parser_node *n, t_rdr_node *l, t_out_in_file *file, int v);
void	*rdr_output(t_parser_node *n, t_rdr_node *l, \
		t_out_in_file *file, int v);
void	*herdoc_(t_parser_node *n, t_rdr_node *l, t_out_in_file *file, int v);
char	*get_herdoc_file(t_rdr_node *rdrlst);
void	redirection(t_parser_node *node);

#endif
