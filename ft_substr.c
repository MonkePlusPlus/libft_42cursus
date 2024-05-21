/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:32:19 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/19 16:14:14 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*str;

	if (start >= ft_strlen(s))
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		return (str);
	}
	len_s = ft_strlen(s + start);
	if (len_s > len)
		len_s = len;
	str = malloc((len_s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len_s] = 0;
	while (len_s-- > 0)
		str[len_s] = s[start + len_s];
	return (str);
}
