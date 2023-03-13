/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:05:33 by hqixeo            #+#    #+#             */
/*   Updated: 2022/08/04 11:05:34 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_findsign(char *str)
{
	if (ft_strchr(str, '-') || ft_strchr(str, '+') || ft_strchr(str, ' '))
		return (1);
	else if (ft_strstr(str, "0x") || ft_strstr(str, "0X"))
		return (2);
	else
		return (0);
}

static char	*ft_period_string(char *str, t_flags *flags)
{
	char	*tmp;

	if ((int)ft_strlen(str) > flags->precision)
	{
		tmp = str;
		str = ft_substr(str, 0, flags->precision);
		free(tmp);
	}
	return (str);
}

static char	*ft_period(char *str, t_flags *flags)
{
	int	len_fill;
	int	sign;

	if (flags->format == 's')
		return (ft_period_string(str, flags));
	sign = ft_findsign(str);
	if (!flags->precision && (str[sign] == '0' && !str[sign + 1]))
		str[sign] = 0;
	len_fill = flags->precision + sign - ft_strlen(str);
	return (ft_strfill(str, '0', len_fill, ft_strrjoin));
}

static char	*ft_setsign(char *str, t_flags *flags)
{
	char	*set;
	char	*sign;

	if (flags->format == 'u' || flags->format == 's' || flags->format == 'o')
		return (str);
	set = ft_strskipchr(str, ' ');
	sign = ft_strskipchr(set, '0');
	if (*sign == '-' || *sign == '+'
		|| (*sign == ' ' && ft_isdigit(*(sign + 1))))
		ft_swapchar(sign, set);
	else if (*sign == 'x' || *sign == 'X')
		ft_swapchar(sign, ++set);
	return (str);
}

char	*ft_strfinalize(char *str, t_flags *flags)
{
	int	len_fill;

	if (flags->period)
		str = ft_period(str, flags);
	len_fill = flags->width - ft_strlen(str);
	if (flags->negative_field)
		str = ft_strfill(str, ' ', len_fill, ft_strjoin);
	else if (flags->zero && !flags->period)
		str = ft_strfill(str, '0', len_fill, ft_strrjoin);
	else if (flags->width)
		str = ft_strfill(str, ' ', len_fill, ft_strrjoin);
	return (ft_setsign(str, flags));
}
