/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudanaci <mudanaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:41:43 by mudanaci          #+#    #+#             */
/*   Updated: 2023/02/17 17:37:54 by mudanaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void		ft_putchar(char c, int *result);
void		ft_putstr(char *s, int *result);
void		ft_putnbr(int i, int *result);
void		ft_unsigned(unsigned int i, int *result);
void		ft_pointer(unsigned long long i, int *result);
void		ft_dhex(unsigned int i, int *result);
void		ft_uhex(unsigned int i, int *result);
void		ft_check(va_list *list, char c, int *result);
int			ft_printf(const char *s, ...);

#endif