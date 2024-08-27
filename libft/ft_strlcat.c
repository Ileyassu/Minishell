/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:05:31 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 20:05:47 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	ldest;
	unsigned int	i;
	unsigned int	result;

	ldest = 0;
	i = 0;
	result = 0;
	while (dest[ldest])
		ldest++;
	while (src[result])
		result++;
	if (size <= ldest)
		result += size;
	else
		result += ldest;
	while (src[i] && (ldest + 1) < size)
	{
		dest[ldest] = src[i];
		ldest++;
		i++;
	}
	dest[ldest] = '\0';
	return (result);
}
