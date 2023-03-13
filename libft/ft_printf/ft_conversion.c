/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:04:44 by hqixeo            #+#    #+#             */
/*   Updated: 2022/08/04 11:04:45 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_printwidth(char fill, int width, int fd)
{
	return (ft_strrelease_fd(ft_strfill(0, fill, width, ft_strjoin), fd));
}

static int	ft_character(char c, t_flags *flags)
{
	if (!flags->width)
		return (ft_putchar_fd(c, flags->fd));
	else if (flags->negative_field)
		return (ft_putchar_fd(c, flags->fd)
			+ ft_printwidth(' ', flags->width - 1, flags->fd));
	else if (flags->zero)
		return (ft_printwidth('0', flags->width - 1, flags->fd)
			+ ft_putchar_fd(c, flags->fd));
	else
		return (ft_printwidth(' ', flags->width - 1, flags->fd)
			+ ft_putchar_fd(c, flags->fd));
}

static char	*ft_decimal(int d, t_flags *flags)
{
	if (d < 0)
		return (ft_itoa(d));
	else if (flags->plus)
		return (ft_strmodify(ft_itoa(d), "+", ft_strrjoin));
	else if (flags->space)
		return (ft_strmodify(ft_itoa(d), " ", ft_strrjoin));
	else
		return (ft_itoa(d));
}

static char	*ft_unsigned(uintptr_t hex, t_flags *flags)
{
	char	*str;

	if (flags->format == 'p')
		return (ft_strmodify(ft_utoa_base(hex, "0123456789abcdef"),
				"0x", ft_strrjoin));
	else if (flags->format == 'u')
		return (ft_utoa_base(hex, "0123456789"));
	else if (flags->format == 'x')
		str = ft_utoa_base(hex, "0123456789abcdef");
	else if (flags->format == 'X')
		str = ft_utoa_base(hex, "0123456789ABCDEF");
	else if (flags->format == 'o')
		str = ft_utoa_base(hex, "01234567");
	else
		return (0);
	if (*str == '0' || !flags->sharp)
		return (str);
	else if (flags->format == 'x')
		return (ft_strmodify(str, "0x", ft_strrjoin));
	else if (flags->format == 'X')
		return (ft_strmodify(str, "0X", ft_strrjoin));
	else if (flags->format == 'o')
		return (ft_strmodify(str, "0", ft_strrjoin));
	return (str);
}

int	ft_conversion(va_list args, t_flags *flags)
{
	char	*str;

	if (flags->format == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (flags->format == 'd' || flags->format == 'i')
		str = ft_decimal(va_arg(args, int), flags);
	else if (flags->format == 'p')
		str = ft_unsigned(va_arg(args, uintptr_t), flags);
	else if (flags->format == 'u' || flags->format == 'o'
		|| flags->format == 'x' || flags->format == 'X')
		str = ft_unsigned(va_arg(args, unsigned int), flags);
	else if (flags->format == 'c')
		return (ft_character(va_arg(args, int), flags));
	else if (flags->format)
		return (ft_character(flags->format, flags));
	else
		return (0);
	if (!str)
		str = ft_strdup("(null)");
	return (ft_strrelease_fd(ft_strfinalize(str, flags), flags->fd));
}
