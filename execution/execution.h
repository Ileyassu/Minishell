/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:27:36 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 22:27:39 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "./builtins/builtins.h"
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>

int		check_path(char *path);
void	*launch_executabl(t_parser_node *root, int size);
void	execution_cmd(t_parser_node *root);
void	execution(t_parser_node *root);
char	**copy_env(int size, int index);
void	free_env(char **env, int index);
void	copy_argv_for_execve(char **root_argv, char **args, char *first_arg);
int		execute_file(char *path, char **argv, char **env, int v);
void	*searsh_in_path(char *path, char **argv, char **env, char **args);
void	free_path_content(char **split_content);

#endif
