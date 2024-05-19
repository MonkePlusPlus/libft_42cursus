/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:14:37 by ptheo             #+#    #+#             */
/*   Updated: 2024/04/01 17:14:38 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptrdest;
	char	*ptrsrc;

	if (!dest || !src)
		return (NULL);
	ptrdest = (char *)dest;
	ptrsrc = (char *)src;
	if (ptrdest > ptrsrc)
	{
		while (n-- > 0)
			ptrdest[n] = ptrsrc[n];
	}
	else
	{
		i = -1;
		while (++i < n)
			ptrdest[i] = ptrsrc[i];
	}
	return (dest);
}
