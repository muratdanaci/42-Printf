/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudanaci <mudanaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:38:02 by mudanaci          #+#    #+#             */
/*   Updated: 2023/03/07 15:25:46 by mudanaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char c, va_list va)
{
	int	sum;

	sum = 0;
	if (c == 'c')
		sum += ft_putchar(va_arg(va, int));
	else if (c == 's')
		sum += ft_putstr(va_arg(va, char *));
	else if (c == 'd' || c == 'i')
		sum += ft_putnbr(va_arg(va, int), 10, 0);
	else if (c == 'u')
		sum += ft_putnbr(va_arg(va, unsigned int), 10, 0);
	else if (c == 'x')
		sum += ft_putnbr(va_arg(va, unsigned int), 16, 0);
	else if (c == 'X')
		sum += ft_putnbr(va_arg(va, unsigned int), 16, 1);
	else if (c == 'p')
		sum += ft_putptr(va_arg(va, unsigned long), 16, 0);
	else
		sum += ft_putchar(c);
	return (sum);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		sum;

	va_start(va, str);
	sum = 0;
	while (*str)
	{
		if (*str == '%')
		{
			sum += ft_control(*(str + 1), va);
			str++;
		}
		else
			sum += ft_putchar(*str);
		str++;
	}
	va_end(va);
	return (sum);
}
