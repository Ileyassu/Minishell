/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:22:07 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/20 01:13:49 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	node_clear(t_parse_node *node)
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

void	node_del(t_parse_node **node)
{
	t_parse_node	*tmp;

	tmp = *node;
	if (tmp)
	{
		node_del(&tmp->left);
		node_del(&tmp->right);
		node_clear(tmp);
	}
}
