/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:48:43 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/17 00:48:48 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

int	ft_printf_core(int fd, const char *str, va_list args,
			int (ft_put)(const char *str, int fd))
{
	int		len_total;
	char	*str_conversion;
	t_flags	flags;

	len_total = 0;
	flags.fd = fd;
	str_conversion = ft_strchr(str, '%');
	while (str_conversion)
	{
		len_total += write(flags.fd, str, str_conversion - str);
		str = ft_flagextract(str_conversion, &flags, args);
		if (!flags.format)
			break ;
		len_total += ft_conversion(args, &flags);
		str_conversion = ft_strchr(++str, '%');
	}
	len_total += ft_put(str, fd);
	va_end(args);
	return (len_total);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	return (ft_printf_core(1, str, args, ft_putstr_fd));
}

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	args;

	if (fd < 0 || fd >= 1024)
		return (-1);
	va_start(args, str);
	return (ft_printf_core(fd, str, args, ft_putstr_fd));
}

int	ft_printf_endl(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	return (ft_printf_core(1, str, args, ft_putendl_fd));
}

int	ft_dprintf_endl(int fd, const char *str, ...)
{
	va_list	args;

	if (fd < 0 || fd >= 1024)
		return (-1);
	va_start(args, str);
	return (ft_printf_core(fd, str, args, ft_putendl_fd));
}
