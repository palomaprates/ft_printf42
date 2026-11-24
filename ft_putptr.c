#include "ft_printf.h"

int	ft_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr >= 16)
	{
		i += ft_ptr(ptr / 16);
		i += ft_ptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			i += ft_putchar(ptr + 48);
		else
			i += ft_putchar(ptr - 10 + 'a');
	}
	return (i);
}

int	ft_putptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		i += ft_putstr("(nil)");
	else
	{
		i += ft_putstr("0x");
		i += ft_ptr(ptr);
	}
	return (i);
}
