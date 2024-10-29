/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:51:21 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/27 20:52:41 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len++;
			if (format[i] == 'c')
				len += ft_print_char(va_arg(args, int));
			else if (format[i] == 's')
				len += ft_print_str(va_arg(args, char *));
			else if (format[i] == 'd' || format[len] == 'i')
				len += ft_print_int(va_arg(args, int));
			else if (format[i] == 'u')
				len += ft_print_unsigned(va_arg(args, unsigned int));
			else if (format[i] == 'x' || format[len] == 'X')
				len += ft_print_hex(va_arg(args, unsigned int), format[i]);
			// else if (format[i] == 'p')
			// 	len += ft_print_pointer(va_arg(args, void *));
			// else if (format[i] == '%')
			// 	len += ft_print_percent();
		}
		else
			len += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
