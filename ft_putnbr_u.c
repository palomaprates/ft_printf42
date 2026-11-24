/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates <pprates@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:54:58 by pprates           #+#    #+#             */
/*   Updated: 2026/11/24 12:54:59 by pprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	long	nbr;
	char	c;
	int		i;

	nbr = nb;
	i = 0;
	if (nbr == 0)
	{
		i += ft_putchar('0');
		return (i);
	}
	if (nbr >= 10)
		i += ft_putnbr_u(nbr / 10);
	c = nbr % 10 + 48;
	i += ft_putchar(c);
	return (i);
}
