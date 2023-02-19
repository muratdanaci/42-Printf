/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudanaci <mudanaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:32:20 by mudanaci          #+#    #+#             */
/*   Updated: 2023/02/17 17:09:09 by mudanaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *result)
{
	write(1, &c, 1);
	*result += 1;
}

void	ft_putstr(char *s, int *result)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", result);
		result += 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], result);
		i++;
	}
}

void	ft_putnbr(int i, int *result)
{
	int	n;

	n = 0;
	if (i == -2147483648)
		return (ft_putstr("-2147483648", result));
	else if (i < 0)
	{
		ft_putchar('-', result);
		ft_putnbr(-i, result);
	}
	else if (i > 9)
	{
		ft_putnbr(i / 10, result);
		ft_putchar(i % 10 + '0', result);
	}
	else
		ft_putchar(i + '0', result);
}

void	ft_unsigned(unsigned int i, int *result)
{
	if (i > 9)
	{
		ft_putnbr(i / 10, result);
		ft_putnbr(i % 10, result);
	}
	else
		ft_putchar(i + '0', result);
}

void	ft_pointer(unsigned long long i, int *result)
{
	char	*base;

	base = "0123456789abcdef";
	if (i >= 16)
	{
		ft_pointer(i / 16, result);
		ft_pointer(i % 16, result);
	}
	else
		ft_putchar(base[i], result);
}
