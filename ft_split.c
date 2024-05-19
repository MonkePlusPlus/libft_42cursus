/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:55:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/04/03 23:55:16 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	count;
	int	i;
	int	first;

	i = 0;
	first = 1;
	while (s[i])
	{
		if (first && s[i] != c)
		{
			first = 0;
			count++;
		}
		if (!first && s[i] == c)
			first = 1;
		i++;
	}
	return (count);
}

int	check_ifc(char const *s, int i, char c, int chec)
{
	while (s[i] && ((chec && s[i] == c) || (!chec && s[i] != c)))
		i++;
	return (i);
}

void	fullfill(char const *s, char *result, int start, int end)
{
	int	i;

	i = 0;
	while (s[start] && start < end)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		first;
	int		i;
	int		index;

	i = 0;
	index = 0;
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[i])
	{
		i = check_ifc(s, i, c, 1);
		if (s[i] != c && s[i])
		{
			first = i;
			i = check_ifc(s, i, c, 0);
			result[index] = malloc(((i - first) + 1) * sizeof(char));
			if (!result)
				return (NULL);
			fullfill(s, result[index], first, i);
			index++;
		}
	}
	return (result[index] = 0, result);
}
