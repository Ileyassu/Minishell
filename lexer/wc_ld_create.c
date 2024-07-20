/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_ld_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:44:55 by mel-hous          #+#    #+#             */
/*   Updated: 2022/11/13 11:21:58 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <dirent.h>
#include <unistd.h>

t_wc_node	*wc_ld_create(char *s)
{
	DIR				*dp;
	struct dirent	*dirp;
	t_wc_node		*lst;

	lst = NULL;
	dp = opendir(".");
	dirp = readdir(dp);
	while (dirp)
	{
		if (is_match(s, dirp->d_name, 0, NULL))
			lstadd_back_dir(&lst, lstnew_dir(ft_strdup(dirp->d_name),
					dirp->d_reclen));
		dirp = readdir(dp);
	}
	closedir(dp);
	return (lst);
}
