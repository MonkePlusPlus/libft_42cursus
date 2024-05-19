/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:13:50 by ptheo             #+#    #+#             */
/*   Updated: 2024/04/01 17:13:52 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptrs;
	unsigned char	c2;
	size_t			i;

	i = 0;
	c2 = (unsigned char)c;
	ptrs = (unsigned char *)s;
	while (i < n)
	{
		if (ptrs[i] == c2)
			return (ptrs + i);
		i++;
	}
	return (NULL);
}
