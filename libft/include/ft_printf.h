/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:03:19 by hqixeo            #+#    #+#             */
/*   Updated: 2022/07/17 01:03:20 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct flags
{
	int	fd;
	int	format;
	int	plus;
	int	space;
	int	sharp;
	int	negative_field;
	int	zero;
	int	period;
	int	width;
	int	precision;
}			t_flags;

int		ft_printf_core(int fd, const char *str, va_list args,
			int (ft_put)(const char *str, int fd));
int		ft_printf(const char *str, ...);
int		ft_dprintf(int fd, const char *str, ...);
int		ft_printf_endl(const char *str, ...);
int		ft_dprintf_endl(int fd, const char *str, ...);

char	*ft_flagextract(const char *str, t_flags *flags, va_list args);
int		ft_conversion(va_list args, t_flags *flags);
char	*ft_strfinalize(char *str, t_flags *flags);

#endif
