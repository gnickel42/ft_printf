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

int	ft_print_ptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_print_str("0x0"));
	len = ft_print_str("0x");
	if (len == -1)
		return (-1);
	len += ft_print_hex((unsigned long)ptr, false);
	if (len == -1)
		return (-1);
	return (len);
}
