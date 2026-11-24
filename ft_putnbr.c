/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates <pprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:55:02 by pprates           #+#    #+#             */
/*   Updated: 2026/11/24 12:55:03 by pprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	nbr;
	char	c;
	int		res;
	int		written;
	res = 0;
	nbr = nb;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		written = ft_putchar('-');
		if (written < 0)
			return (-1);
	}
	if (nbr >= 10)
	{
		written = ft_putnbr(nbr / 10);
		if (written < 0)
			return (-1);
		res += written;
	}
	written = ft_putchar(nbr % 10 + '0');
	if (written < 0)
		return (-1);
	return (res + written);
}

