/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:15:40 by ptheo             #+#    #+#             */
/*   Updated: 2024/04/01 17:15:41 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	while (s[i])
	{
		if (s[i] == (char)c)
			temp = (char *)&s[i];
		i++;
	}
	return (temp);
}
