/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:07:42 by mprofett          #+#    #+#             */
/*   Updated: 2022/11/24 10:07:44 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr(long long int nbr, int *len)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		*len += 1;
		nbr *= -1;
	}
	if (nbr > 9)
	{
		putnbr(nbr / 10, len);
		ft_putchar_fd(((nbr % 10) + 48), 1);
		*len += 1;
	}
	else
		ft_putchar_fd((nbr + 48), 1);
}

void	putnbr_hexa(unsigned int nbr, int *len, int lowercase)
{
	if ((nbr / 16) != 0 && *len < 8)
	{
		putnbr_hexa(nbr / 16, len, lowercase);
		*len += 1;
	}
	ft_put_hexa_char_fd(nbr % 16, lowercase, 1);
}

void	putnbr_pointer(unsigned long long nbr, int *len)
{
	if ((nbr / 16) != 0)
	{
		putnbr_pointer(nbr / 16, len);
		*len += 1;
	}
	ft_put_hexa_char_fd(nbr % 16, 1, 1);
}

int	print_variable(va_list *ap, char var_type)
{
	if (var_type == 'c')
		return (ft_putchar_fd(va_arg(*ap, int), 1));
	else if (var_type == 's')
		return (print_str(ap));
	else if (var_type == 'd' || var_type == 'i')
		return (print_number(ap));
	else if (var_type == 'u')
		return (print_unsigned_number(ap));
	else if (var_type == 'p')
		return (print_pointer(ap));
	else if (var_type == 'x')
		return (print_hexa(ap, 1));
	else if (var_type == 'X')
		return (print_hexa(ap, 0));
	else if (var_type == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		var_len;

	i = -1;
	count = 0;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			var_len = print_variable(&ap, s[++i]);
			if (var_len == -1)
				return (-1);
			count += var_len;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			++count;
		}
	}
	va_end(ap);
	return (count);
}
