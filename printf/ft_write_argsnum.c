/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_argsnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:30:06 by aatan             #+#    #+#             */
/*   Updated: 2024/01/31 18:42:24 by aatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(va_list *args)
{
	int	nb;
	int	count;

	count = 0;
	nb = va_arg(*args, int);
	count += ft_putnbr(nb);
	return (count);
}

int	ft_print_unsignednum(va_list *args)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(*args, unsigned int);
	count = 0;
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}

int	ft_print_hexa(char format, va_list *args)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = va_arg(*args, unsigned int);
	count += ft_puthexa(nb, format);
	return (count);
}
