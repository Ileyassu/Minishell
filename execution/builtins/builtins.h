/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:01:21 by zmoussam          #+#    #+#             */
/*   Updated: 2024/07/20 01:13:49 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include<string.h>
# include<errno.h>
# include "../../env1/env.h"
# include "../../parsing/parser.h"
# include "../../lexer/lexer.h"

void		echo(t_parse_node *root);
void		env_cmd(t_parse_node *root);
void		cd(t_parse_node *root);
void		go_to_home(char **oldpwd, char **pwd, t_env_node *tmp_home, \
		char *old_d);
void		go_to_oldpath(char **oldpwd, char **pwd);
void		set_oldpwd(char **oldpwd, char *new_oldpwd, int msg);
void		set_pwd(char **pwd);
void		pwd(t_parse_node *root);
void		unset(t_parse_node *root, int index);
void		exit_cmd(t_parse_node *root);
void		export(t_parse_node *root);
t_env_node	*get_new_node(char *variable_with_content, int index);
void		intialise_len_variable(void);
t_env_node	get_min_variable(t_env_node min);
t_env_node	get_max_variable(void);
void		print_sort_list(void);
int			check_sign_plus(char *name, char *content);
int			check_special_char(char *name, char *content, int len, int _op_er);
int			parss_export_variable(t_env_node *node, int _op_error);

#endif
