/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudanaci <mudanaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:38:02 by mudanaci          #+#    #+#             */
/*   Updated: 2023/02/17 17:37:20 by mudanaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dhex(unsigned int i, int *result)
{
	char	*base;

	base = "0123456789abcdef";
	if (i >= 16)
	{
		ft_dhex(i / 16, result);
		ft_dhex(i % 16, result);
	}
	else
		ft_putchar(base[i], result);
}

void	ft_uhex(unsigned int i, int *result)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (i >= 16)
	{
		ft_uhex(i / 16, result);
		ft_uhex(i % 16, result);
	}
	else
		ft_putchar(base[i], result);
}

void	ft_check(va_list *list, char c, int *result)
{
	if (c == 'c')
		ft_putchar(va_arg(*list, int), result);
	else if (c == '%')
		ft_putchar('%', result);
	else if (c == 's')
		ft_putstr(va_arg(*list, char *), result);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*list, int), result);
	else if (c == 'x')
		ft_dhex(va_arg(*list, unsigned long long), result);
	else if (c == 'X')
		ft_uhex(va_arg(*list, unsigned long long), result);
	else if (c == 'u')
		ft_unsigned(va_arg(*list, unsigned int), result);
	else if (c == 'p')
	{
		ft_putstr("0x", result);
		ft_pointer(va_arg(*list, unsigned long long), result);
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		result;
	va_list	list;

	i = 0;
	result = 0;
	va_start(list, s);

	while (s[i] && s)
	{
		if (s[i] == '%' && s[i + 1])
			ft_check(&list, s[++i], &result);
		else
			ft_putchar(s[i], &result);
		i++;
	}
	va_end (list);
	return (result);
}
