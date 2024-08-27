/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:07:13 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 21:07:15 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	node_clear(t_parser_node *node)
{
	int	i;

	i = 0;
	if (node)
	{
		while (node->av && node->av[i])
			free(node->av[i++]);
		free(node->av);
		rdr_clear(&node->rdrlst);
		free(node);
	}
}

void	node_del(t_parser_node **node)
{
	t_parser_node	*tmp;

	tmp = *node;
	if (tmp)
	{
		node_del(&tmp->left);
		node_del(&tmp->right);
		node_clear(tmp);
	}
}
