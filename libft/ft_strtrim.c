/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:06:12 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 20:05:47 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strbegin(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr_ex(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_strend(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen((char *)s1);
	while (i >= 0)
	{
		if (ft_strchr_ex(set, s1[i]) == 0)
			break ;
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	char	*dest;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	begin = ft_strbegin(s1, set);
	end = ft_strend(s1, set);
	if (begin >= end)
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * (end - begin + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, (char *)s1 + begin, end - begin + 1);
	return (dest);
}
