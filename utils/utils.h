/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:08:52 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 22:08:51 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <signal.h>
# include <stdlib.h>

typedef struct s_wc_node
{
	char				*d_name;
	int					len;
	struct s_wc_node	*next;
}						t_wc_node;

typedef struct s_cmd
{
	t_wc_node			*wc;
	char				*word;
	struct s_cmd		*next;
}						t_cmd;

t_cmd					*ft_new_cmd(char *content, t_wc_node **list);
void					cmd_addback(t_cmd **lst, t_cmd *new);
t_cmd					*cmd_lstlast(t_cmd *lst);
t_wc_node				*lstlast_dir(t_wc_node *lst);
void					lstadd_back_dir(t_wc_node **lst, t_wc_node *new_ld);
t_wc_node				*lstnew_dir(char *content, int len);
int						wc_size(t_wc_node *lst);
int						cmd_size(t_cmd *lst);
void					wc_clear(t_wc_node **lst);
void					cmd_clear(t_cmd **lst);
char					*remove_q(char *s);
void					ft_clear_av(char **str);
void					put_line(char *line, int fd);
int						readline_hook(void);
void					intialize_signal(void);
void					check_sigquit_(void);
void					free_env_list(void);
const char				*get_wd(char *path);

#endif