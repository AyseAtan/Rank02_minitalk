/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:27:55 by aatan             #+#    #+#             */
/*   Updated: 2024/01/09 15:26:31 by aatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_check_types(va_list *args, const char format);
int		ft_printf(const char *format, ...);

//ft_write_args.c
int		ft_print_char(va_list *args);
int		ft_print_string(va_list *args);
int		ft_print_pointer(va_list *args);

//ft_write_argsnum.c
int		ft_print_num(va_list *args);
int		ft_print_unsignednum(va_list *args);
int		ft_print_hexa(char var, va_list *args);

//ft_libf.c
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_puthexa(unsigned long nb, char var);
size_t	ft_strlen(const char *str);

#endif
