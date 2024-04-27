#include "minishell.h"

void cmnd_add_back(t_comands **cmnds, t_comands *new)
{
    t_comands *tmp;

    tmp = *cmnds;
    if(*cmnds == NULL)
    {
        *cmnds = new;
        return ;
    }
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}

t_comands *commands(char **str, t_parser *parser)
{
    t_comands *new_cmd;
    new_cmd = malloc(sizeof(t_comands));
    new_cmd->str = str;
    new_cmd->number_of_redirections = parser->count_redirections;
    new_cmd->redirections = parser->redirections;
    new_cmd->next = NULL;
    new_cmd->prev = NULL;
    return (new_cmd);
}
void cmnd_clear (t_comands **cmnd)
{
    t_comands *tmp;
    t_lexer *redirection_tmp;

    if (!(*cmnd))
        return;
    while((*cmnd))
    {
        tmp = (*cmnd)->next;
        redirection_tmp = (*cmnd)->redirections;
        clear_node(&redirection_tmp);
        if ((*cmnd)->str)
            free((*cmnd)->str);
        free(*cmnd);
        (*cmnd) = tmp;
    }
}
int	count_args(t_lexer *lexer_list)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lexer_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->index >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_comands *init_comands(t_parser *parser)
{
    char **str;
    int i;
    t_lexer *tmp;
    int arg_size;
    t_comands *cmd;

    i = 0;
    cmd = NULL;
    arg_size = count_args(parser->lexer);
    str = ft_calloc(arg_size + 1, sizeof(char *));
    remove_redirections(parser);
    printf("arg size = %d\n", arg_size);
    tmp = parser->lexer;
    while(arg_size > 0)
    {
        if (tmp->str)
        {
            str[i] = ft_strdup(tmp->str);
            //printf("str = %s\n",str[i]);
            delete_node_by_index(&parser->lexer, tmp->index);
            tmp = parser->lexer;
        }
        arg_size--;
    }
    while (str[i])
    {
        printf("str = %s\n", str[i++]);
    }
    cmd = commands(str, parser);
    return (cmd);
}

int parse(t_tools *tools)
{
    t_comands *cmnd;
    t_parser parser;

    tools->cmnds = NULL;
    pipe_counter(tools);

    if(tools->lexer->token == PIPE)
    {
        return (double_token_error(PIPE, tools));
    }   
    while(tools->lexer)
    {
        if(tools->lexer->token == PIPE && tools->lexer)
            delete_node_by_index(&tools->lexer, tools->lexer->index);
        if(tools->lexer->token == PIPE && tools->lexer)
        {
            double_token_error(PIPE, tools);
            return(0);
        }
        parser = init_parser(tools->lexer, tools);

        cmnd = init_comands(&parser);
        if (!tools->cmnds)
            tools->cmnds = cmnd;
        else
        {
            cmnd_add_back(&tools->cmnds, cmnd);
        }
        tools->lexer = parser.lexer;
    }
    return 1;
}