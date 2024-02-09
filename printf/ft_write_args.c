/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:37:31 by aatan             #+#    #+#             */
/*   Updated: 2024/01/31 18:42:17 by aatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(va_list *args)
{
	char	*s;
	int		i;

	s = va_arg(*args, char *);
	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	return (i);
}

int	ft_print_pointer(va_list *args)
{
	unsigned long	nb;
	int				count;
	int				*p;

	count = 0;
	p = va_arg(*args, void *);
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	nb = (unsigned long)p;
	count += ft_putstr("0x");
	count += ft_puthexa(nb, 'x');
	return (count);
}
