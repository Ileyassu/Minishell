/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:03:43 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/20 01:03:45 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (dest[i] == (unsigned char)c)
			return ((void *)&dest[i]);
		i++;
	}
	return (NULL);
}
