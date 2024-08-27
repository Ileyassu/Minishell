/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:06:17 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/07/21 20:05:47 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int beg, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (beg >= ft_strlen(s))
		return (ft_strdup(""));
	if (len == -1)
		len = ft_strlen(s) - (beg);
	if (len > (int)ft_strlen(&s[beg]))
		len = ft_strlen(&s[beg]);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[beg + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
