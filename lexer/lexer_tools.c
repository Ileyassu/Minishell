#include "../minishell.h"

void	ft_lexeradd_back(t_lexer **list, t_lexer *new)
{
	t_lexer	*tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_lexer	*ft_lexernew(char *str, int token)
{
	t_lexer		*new_element;
	static int	i = 0;

	new_element = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->token = token;
	new_element->i = i++;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

int	add_node(char *str, t_tokens token, t_lexer **lexer)
{
	t_lexer	*node;

	node = ft_lexernew(str, token);
	if (!node)
		return (0);
	ft_lexeradd_back(lexer, node);
	return (1);
}

void	ft_lexerclear(t_lexer **list)
{
	t_lexer	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->str)
			free((*list)->str);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

t_lexer	*ft_lexerclear_one(t_lexer **list)
{
	if ((*list)->str)
	{
		free((*list)->str);
		(*list)->str = NULL;
	}
	free(*list);
	*list = NULL;
	return (NULL);
}

void	ft_lexerdel_first(t_lexer **list)
{
	t_lexer	*node;

	node = *list;
	*list = node->next;
	ft_lexerclear_one(&node);
	if (*list)
		(*list)->prev = NULL;
}

void	delete_lexer_node(t_lexer **list, int key)
{
	t_lexer	*node;
	t_lexer	*prev;
	t_lexer	*start;

	start = *list;
	node = start;
	if ((*list)->i == key)
	{
		ft_lexerdel_first(list);
		return ;
	}
	while (node && node->i != key)
	{
		prev = node;
		node = node->next;
	}
	if (node)
		prev->next = node->next;
	else
		prev->next = NULL;
	if (prev->next)
		prev->next->prev = prev;
	ft_lexerclear_one(&node);
	*list = start;
}

t_tokens	check_token(int c)
{
	static int	token_arr[3][2] = {
	{'|', PIPE},
	{'>', GREAT},
	{'<', LESS},
	};
	int			i;

	i = 0;
	while (i < 3)
	{
		if (token_arr[i][0] == c)
			return (token_arr[i][1]);
		i++;
	}
	return (0);
}
