/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:07:35 by mprofett          #+#    #+#             */
/*   Updated: 2022/11/24 10:07:37 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list *ap)
{
	int		i;
	char	*str;

	i = -1;
	str = va_arg(*ap, char *);
	if (str)
		while (str[++i])
			ft_putchar_fd(str[i], 1);
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (i);
}

int	print_number(va_list *ap)
{
	int	len;
	int	n;

	len = 1;
	n = va_arg(*ap, int);
	putnbr(n, &len);
	return (len);
}

int	print_hexa(va_list *ap, int lowercase)
{
	int				len;
	unsigned long	n;

	len = 1;
	if (lowercase == 2)
	{
		len += 2;
		write(1, "0x", 2);
	}
	n = va_arg(*ap, unsigned long);
	putnbr_hexa(n, &len, lowercase);
	return (len);
}

int	print_pointer(va_list *ap)
{
	int					len;
	unsigned long long	n;

	len = 3;
	write(1, "0x", 2);
	n = va_arg(*ap, unsigned long long);
	putnbr_pointer(n, &len);
	return (len);
}

int	print_unsigned_number(va_list *ap)
{
	int				len;
	unsigned int	n;

	len = 1;
	n = va_arg(*ap, unsigned int);
	putnbr(n, &len);
	return (len);
}
