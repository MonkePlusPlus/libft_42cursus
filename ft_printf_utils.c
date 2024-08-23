/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:59:48 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/25 15:54:54 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg_aux(char *str, va_list argptr)
{
	int	count;

	count = 0;
	if (*str == 'x')
		count = print_hexa(va_arg(argptr, int), "0123456789abcdef");
	else if (*str == 'X')
		count = print_hexa(va_arg(argptr, int), "0123456789ABCDEF");
	else if (*str == 'u')
		count = ft_printnbr(va_arg(argptr, unsigned int));
	else if (*str == '%')
	{
		write(1, "%", 1);
		count += 1;
	}
	else
		return (-1);
	return (count);
}

int	print_arg(char *str, va_list argptr)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count = print_char(va_arg(argptr, unsigned int));
	else if (*str == 's')
		count = print_str(va_arg(argptr, char *));
	else if (*str == 'p')
		count = print_ptr(va_arg(argptr, void *));
	else if (*str == 'd')
		count = print_int(va_arg(argptr, int));
	else if (*str == 'i')
		count = print_int(va_arg(argptr, int));
	else
		count = print_arg_aux(str, argptr);
	return (count);
}

int	print_hexa(unsigned int nbr, char *hexa)
{
	size_t	count;
	char	c;

	count = 0;
	if (nbr > 15)
	{
		count += print_hexa(nbr / 16, hexa);
		c = hexa[nbr % 16];
		write(1, &c, 1);
		count += 1;
	}
	else
	{
		c = hexa[nbr];
		write(1, &c, 1);
		count += 1;
	}
	return (count);
}

int	print_hexaptr(unsigned long long nbr, char *hexa)
{
	size_t	count;
	char	c;

	count = 0;
	if (nbr > 15)
	{
		count += print_hexaptr(nbr / 16, hexa);
		c = hexa[nbr % 16];
		write(1, &c, 1);
		count += 1;
	}
	else
	{
		c = hexa[nbr];
		write(1, &c, 1);
		count += 1;
	}
	return (count);
}
