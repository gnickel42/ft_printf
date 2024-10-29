/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:42:53 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/29 09:42:53 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return(write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;
	i = 0;

	if (!str)
		return (0);
	while (str[i])
		i += write(1, &str, 1);
	return (i);
}

int	ft_print_int(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	if (n < 0)
	{
		len += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		len += ft_print_int(n / 10);
	len += ft_print_char((n % 10) + '0');
	return (len);
}

int ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_print_int(n / 10);
	len += ft_print_char((n % 10) + '0');
	return (len);
}

int ft_print_hex(unsigned int n, char format)
{
	int		len;
	char	hex_digit;

	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16, format);
	if ((n % 16) > 10)
		hex_digit = (n % 16) + '0';
	else
	{
		if (format == 'x')
			hex_digit = (n % 16) - 10 + 'a';
		else
			hex_digit = (n % 16) - 10 + 'A';
	}
	len += ft_print_char(hex_digit);
	return (len);
}

// int ft_print_pointer(void *ptr)
// {
//
// }
