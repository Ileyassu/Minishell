#include "minishell.h"

char	*find_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
		i++;
	}
	return (ft_strdup("\0"));
}

void	free_arr(char **split_arr)
{
	int	i;

	i = 0;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

char	**ft_arrdup(char **arr)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			free_arr(rtn);
			return (rtn);
		}
		i++;
	}
	return (rtn);
}

int	find_pwd(t_tools *tools)
{
	int	i;

	i = 0;
	while (tools->envp[i])
	{
		if (!ft_strncmp(tools->envp[i], "PWD=", 4))
			tools->pwd = ft_substr(tools->envp[i],
					4, ft_strlen(tools->envp[i]) - 4);
		if (!ft_strncmp(tools->envp[i], "OLDPWD=", 7))
			tools->old_pwd = ft_substr(tools->envp[i],
					7, ft_strlen(tools->envp[i]) - 7);
		i++;
	}
	return (1);
}

// int	parse_envp(t_tools *tools)
// {
// 	char	*path_from_envp;
// 	int		i;
// 	char	*tmp;

// 	path_from_envp = find_path(tools->envp);
// 	tools->paths = ft_split(path_from_envp, ':');
// 	free(path_from_envp);
// 	i = 0;
// 	while (tools->paths[i])
// 	{
// 		if (ft_strncmp(&tools->paths[i][ft_strlen(tools->paths[i]) - 1],
// 			"/", 1) != 0)
// 		{
// 			tmp = ft_strjoin(tools->paths[i], "/");
// 			free(tools->paths[i]);
// 			tools->paths[i] = tmp;
// 		}
// 		i++;
// 	}
// 	return (EXIT_SUCCESS);
// }

void old_pwd_extractor(t_tools *tools)
{
    int i = 0;
    char pwd[] = "OLDPWD";
    int pwd_len = 6;
    int j = 0;
    while(tools->envp[i])
    {
        pwd_len = 6;
        j = 0;
        while(tools->envp[i][j] == pwd[j] && pwd_len > 0)
        {
            pwd_len--;
            j++;
        }
        if (pwd_len == 0)
        {
            tools->old_pwd = ft_substr(tools->envp[i], 7, ft_strlen(tools->envp[i]) - 6);
            break;
        }
        i++;
    }
}
int main(int ac, char **av, char **envp) 
{
    (void)ac;
    (void)av;
    t_tools tools;
    if (!envp)
        return 1;
    tools.envp = ft_arrdup(envp);
    find_pwd(&tools);
    old_pwd_extractor(&tools);
    implement_tools(&tools);
    minishell_loop(&tools);
    //t_lexer *tmp = tools.lexer;
    // while(tmp)
    // {
    //     printf("Index: %d Token: %d, Str: %s\n", tmp->index, tmp->token, tmp->str);
    //     tmp = tmp->next;
    // }
}