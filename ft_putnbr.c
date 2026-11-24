/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates <pprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:55:02 by pprates           #+#    #+#             */
/*   Updated: 2026/11/24 18:18:30 by pprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	nbr;
	int		i;
	int		res;

	i = 0;
	nbr = nb;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		res = ft_putchar('-');
		if (res == -1)
			return (-1);
		i += res;
	}
	if (nbr >= 10)
	{
		res = ft_putnbr(nbr / 10);
		if (res == -1)
			return (-1);
		i += res;
	}
	res = ft_putchar(nbr % 10 + '0');
	if (res == -1)
		return (-1);
	return (i + res);
}
