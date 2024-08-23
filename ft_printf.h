/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:34:06 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/25 15:54:41 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

size_t	ft_printnbr(unsigned long nb);
int		ft_printf(const char *string, ...);
int		print_arg(char *str, va_list argptr);
int		print_char(char c);
int		print_str(char *str);
int		print_ptr(void *ptr);
int		print_int(long nbr);
int		print_hexa(unsigned int nbr, char *hexa);
int		print_hexaptr(unsigned long long nbr, char *hexa);

#endif
