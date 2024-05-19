/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:58:27 by ptheo             #+#    #+#             */
/*   Updated: 2024/04/03 20:58:28 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_malloc(long n)
{
	int		count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count += 1;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	int		count;

	nbr = n;
	count = count_malloc(nbr);
	result = malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		result[0] = '-';
	}
	result[count--] = 0;
	while (nbr > 9)
	{
		result[count--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	result[count] = nbr + '0';
	return (result);
}
