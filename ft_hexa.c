/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates <pprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:58:41 by pprates           #+#    #+#             */
/*   Updated: 2026/11/24 18:12:48 by pprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_char(unsigned int nbr, char specifier)
{
	if (nbr < 10)
		return (ft_putchar(nbr + '0'));
	if (specifier == 'X')
		return (ft_putchar(nbr - 10 + 'A'));
	return (ft_putchar(nbr - 10 + 'a'));
}

int	ft_hexa(unsigned int nbr, char specifier)
{
	int	res;
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		res = ft_hexa(nbr / 16, specifier);
		if (res == -1)
			return (-1);
		i += res;
		res = ft_hexa(nbr % 16, specifier);
		if (res == -1)
			return (-1);
		i += res;
	}
	else
	{
		res = ft_hexa_char(nbr, specifier);
		if (res == -1)
			return (-1);
		i += res;
	}
	return (i);
}
