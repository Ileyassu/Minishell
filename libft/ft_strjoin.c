/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:05:25 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 20:05:47 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		len;
	int		l1;
	int		l2;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	len = l1 + l2;
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_memmove(s, s1, l1);
	ft_memmove((s + l1), s2, l2);
	s[len] = '\0';
	return (s);
}
