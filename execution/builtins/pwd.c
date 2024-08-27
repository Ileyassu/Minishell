/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 22:27:03 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 22:27:06 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	pwd(void)
{
	char	*cwd;
	char	buffer[4096];

	cwd = getcwd(buffer, 4096);
	if (cwd == NULL)
		printf("%s\n", buffer);
	else
		printf("%s\n", cwd);
	g_lbv.exit_status = 0;
}
