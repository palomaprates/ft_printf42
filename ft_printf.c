/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates <pprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:54:50 by pprates           #+#    #+#             */
/*   Updated: 2026/11/24 15:34:23 by pprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_arg(const char *str, int *size, va_list *args)
{
	int	ret;

	if (*str == 's')
		ret = ft_putstr(va_arg(*args, char *));
	else if (*str == 'c')
		ret = ft_putchar(va_arg(*args, int));
	else if (*str == 'd' || *str == 'i')
		ret = ft_putnbr(va_arg(*args, int));
	else if (*str == 'u')
		ret = ft_putnbr_u(va_arg(*args, unsigned int));
	else if (*str == 'x' || *str == 'X')
		ret = ft_hexa(va_arg(*args, unsigned int), *str);
	else if (*str == 'p')
		ret = ft_putptr(va_arg(*args, unsigned long long));
	else if (*str == '%')
		ret = ft_putchar('%');
	else
		return ;
	if (ret < 0)
		*size = -1;
	else if (*size != -1)
		*size += ret;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, str);
	while (*str && size != -1)
	{
		if (*str == '%' && str++)
			print_arg(str, &size, &args);
		else
		{
			if (ft_putchar(*str) == -1)
				size = -1;
			else if (size != -1)
				size++;
		}
		str++;
	}
	va_end(args);
	return (size);
}
