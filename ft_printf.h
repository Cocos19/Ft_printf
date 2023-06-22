/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:07:49 by mprofett          #+#    #+#             */
/*   Updated: 2022/11/24 10:07:55 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
int		print_variable(va_list *ap, char var_type);
int		print_str(va_list *ap);
int		print_number(va_list *ap);
int		print_hexa(va_list *ap, int lowercase);
int		print_unsigned_number(va_list *ap);
void	putnbr(long long nbr, int *len);
void	putnbr_hexa(unsigned int n, int *len, int lowercase);
void	putnbr_pointer(unsigned long long nbr, int *len);
int		print_pointer(va_list *ap);

#endif
