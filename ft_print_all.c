/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:00:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/25 15:55:32 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		print_str("(null)");
		return (6);
	}
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_ptr(void *ptr)
{
	uintptr_t	*nbr;

	nbr = (uintptr_t *)ptr;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (print_hexaptr((unsigned long long)nbr, "0123456789abcdef") + 2);
}

size_t	ft_printnbr(unsigned long nbr)
{
	size_t	count;
	char	c;

	count = 0;
	if (nbr > 9)
	{
		count += ft_printnbr(nbr / 10);
		c = (nbr % 10) + '0';
		write(1, &c, 1);
		count += 1;
	}
	else
	{
		c = (nbr % 10) + '0';
		write(1, &c, 1);
		count += 1;
	}
	return (count);
}

int	print_int(long nbr)
{
	size_t	count;

	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		count++;
	}
	count += ft_printnbr(nbr);
	return (count);
}
