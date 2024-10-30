/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:15:40 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/30 11:15:40 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, bool upper)
{
	int		len;
	char	hex_digit;

	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16, upper);
	if ((n % 16) < 10)
		hex_digit = (n % 16) + '0';
	else
	{
		if (upper)
			hex_digit = (n % 16) - 10 + 'A';
		else
			hex_digit = (n % 16) - 10 + 'a';
	}
	len += ft_print_char(hex_digit);
	return (len);
}
