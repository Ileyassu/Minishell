/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:27:01 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/19 20:27:06 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utils.h"
#include <stdlib.h>

void	ft_clear_av(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free (str[i++]);
	free (str);
}
