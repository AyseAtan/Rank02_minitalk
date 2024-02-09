/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:55:15 by aatan             #+#    #+#             */
/*   Updated: 2024/01/31 18:42:38 by aatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_types(va_list *args, const char format);

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	va_list	args;

	i = 0;
	result = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%' && format[i] != '\0')
		{
			result = result + write(1, &format[i], 1);
		}
		else if (format[i] == '%')
		{
			i++;
			result = result + ft_check_types(&args, format[i]);
		}
		if (format[i] != '\0')
			i++;
	}
	va_end(args);
	return (result);
}

int	ft_check_types(va_list *args, const char format)
{
	int	result;

	if (format == 'c')
		result = ft_print_char(args);
	else if (format == 's')
		result = ft_print_string(args);
	else if (format == 'p')
		result = ft_print_pointer(args);
	else if (format == 'd' || format == 'i')
		result = ft_print_num(args);
	else if (format == 'u')
		result = ft_print_unsignednum(args);
	else if (format == 'x' || format == 'X' )
		result = ft_print_hexa(format, args);
	else if (format == '%')
		result = write (1, "%", 1);
	else
		result = 0;
	return (result);
}
