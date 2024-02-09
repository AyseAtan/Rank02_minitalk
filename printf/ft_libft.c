/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:14:37 by aatan             #+#    #+#             */
/*   Updated: 2024/01/31 18:38:12 by aatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_putstr("-2147483648");
	else if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	else
	{
		count += ft_putchar(n + '0');
	}
	return (count);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (-1);
	return (write(1, s, ft_strlen(s)));
}

int	ft_puthexa(unsigned long nb, char var)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_puthexa(nb / 16, var);
		count += ft_puthexa(nb % 16, var);
	}
	else
	{
		if (nb <= 9)
		{
			count += ft_putchar(nb + '0');
		}
		else
		{
			if (var == 'x')
				count += ft_putchar(nb % 10 + 'a');
			if (var == 'X')
				count += ft_putchar(nb % 10 + 'A');
		}
	}
	return (count);
}

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}
