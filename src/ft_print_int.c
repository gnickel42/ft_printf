/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:13:06 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/30 11:13:06 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
