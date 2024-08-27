/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:11:50 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 21:11:51 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libft/libft.h"
# include <stddef.h>

typedef struct s_env_node
{
	char				*name;
	char				*content;
	int					len;
	struct s_env_node	*next;
}						t_env_node;

t_env_node				*create_env(char **env);
t_env_node				*env_find(t_env_node *env, char *s, int len);
t_env_node				*lstlast(t_env_node *lst);
void					add_back(t_env_node **lst, t_env_node *new);
t_env_node				*new_node(char *content, char *name, int len);
char					*env_find2(t_env_node *env, char *s, int len);
void					ft_list_remove_if(t_env_node **begin_list,
							void *data_ref);
void					delone_env(t_env_node *node);
int						env_listsize(t_env_node *env);
void					print_list(void);
void					_shell_level(t_env_node **lst);
void					_set_pwd(t_env_node **lst);
int						env_find3(t_env_node *env, char *s);

#endif
