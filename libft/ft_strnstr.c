/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:06:02 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 20:05:47 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t n)
{
	size_t	i;
	int		j;

	if (*sub == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == sub[0])
		{
			j = 0;
			while (sub[j] && str[i + j] && i + j < n && str[i + j] == sub[j])
				j++;
			if (sub[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
