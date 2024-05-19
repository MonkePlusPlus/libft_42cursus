/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:44:22 by ptheo             #+#    #+#             */
/*   Updated: 2024/04/03 23:44:23 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		index;
	int		i;
	int		size;

	size = ft_strlen((char *)s1) - 1;
	i = 0;
	index = 0;
	if (set[0] == 0)
		return (ft_strdup((char *)s1));
	while (in_trim(s1[i], set))
		i++;
	while (in_trim(s1[size], set))
		size--;
	str = malloc(((size - i) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] && i <= size)
	{
		str[index++] = s1[i];
		i++;
	}
	str[index] = '\0';
	return (str);
}
