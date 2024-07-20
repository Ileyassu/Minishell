/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:26:44 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/19 20:26:46 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include "../execution/execution.h"
#include <fcntl.h>

void	redirection(t_parser_node *node)
{
	t_out_in_file	in_out_file;

	in_out_file.output_file = 1;
	in_out_file.input_file = 0;
	if (node->rdrlst->type == HERDOC)
		herdoc_(node, node->rdrlst, &in_out_file, 1);
	else if (node->rdrlst->type == RD_OUT || node->rdrlst->type == RD_APP)
		rdr_output(node, node->rdrlst, &in_out_file, 1);
	else if (node->rdrlst->type == RD_IN)
		rdr_input(node, node->rdrlst, &in_out_file, 1);
}
