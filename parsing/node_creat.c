/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:22:01 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/20 01:13:49 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	av_size(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return (0);
	while (*av++)
		i++;
	return (i);
}

t_parse_node	*node_create(t_cmd **av, t_rdr_node *rdrlist, t_token_type tp)
{
	t_parse_node	*node;

	node = malloc(sizeof(t_parse_node));
	if (!node)
		return (NULL);
	node->av = NULL;
	node->rdrlst = NULL;
	if (av)
	{
		node->av = av_creat(av);
		if (!node->av)
			return (NULL);
	}
	node->ac = av_size(node->av);
	node->type = tp;
	if (rdrlist)
		node->rdrlst = rdrlist;
	node->right = NULL;
	node->left = NULL;
	return (node);
}

void	node_ptr(t_parse_node **node, t_parse_node *left,
				t_parse_node *right)
{
	(*node)->right = right;
	(*node)->left = left;
}
