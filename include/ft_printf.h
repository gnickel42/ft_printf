/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:22:00 by gnickel           #+#    #+#             */
/*   Updated: 2024/10/29 09:35:17 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
# include "stdarg.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_int(int i);
int	ft_print_unsigned(unsigned int i);
int	ft_print_hex(unsigned int i, char format);
// int	ft_print_pointer(const void *p);
// int	ft_print_percent(const void *p);

#endif