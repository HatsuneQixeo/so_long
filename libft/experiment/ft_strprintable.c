#include "libft.h"

static void	print(char c)
{
	ft_putchar_fd(c, 1);
}

void	nprint(char c)
{
	print('\\');
	if (c < 16)
	{
		print('0');
		if (c < 10)
			print(c + '0');
		else
			print(c - 10 + 'a');
	}
	else
	{
		print(c - 10 + 'a');
		c %= 16;
		if (c < 10)
			print(c + '0');
		else
			print(c - 10 + 'a');
	}
}

void	ft_putstr_non_printable(const char *str)
{
	str--;
	while (*++str)
	{
		if (ft_isprint(*str))
			ft_putchar_fd(*str, 1);
		else
			nprint(*str);
	}
}

size_t	ft_chrcount_ft(const char *str, int (ft)(int c))
{
	size_t	count;

	count = 0;
	str--;
	while (*++str)
		if (ft(*str))
			count++;
	return (count);
}

static int	ft_setnpc_sign(char *str, char npc)
{
	*str++ = '\\';
	if (npc == '\b')
		*str = 'b';
	else if (npc == '\f')
		*str = 'f';
	else if (npc == '\n')
		*str = 'n';
	else if (npc == '\r')
		*str = 'r';
	else if (npc == '\t')
		*str = 't';
	else
		*str = '0';
	return (2);
}

//Undefined character are represent as '0'
char	*ft_strprintable_sign(const char *src)
{
	char	*str_main;
	char	*tmp;
	size_t	len_src;

	len_src = ft_strlen(src);
	str_main = malloc(len_src + (len_src - ft_chrcount_ft(src, ft_isprint)) * 2
			+ 1);
	if (!str_main)
		return (0);
	tmp = str_main;
	while (*src)
		if (ft_isprint(*src))
			*str_main++ = *src++;
	else
		str_main += ft_setnpc_sign(str_main, *src++);
	*str_main = 0;
	return (tmp);
}

static int	ft_padsize(const char *base)
{
	char	*nbr;
	size_t	size;

	nbr = ft_utoa_base(255, base);
	if (!nbr)
		return (0);
	size = ft_strlen(nbr);
	free(nbr);
	return (size);
}

static int	ft_setnpc(char *str, char npc, const char *base, int len_pad)
{
	char	*str_npc;
	int		pad_size;

	str_npc = ft_utoa_base(npc, base);
	if (!str_npc)
		return (0);
	*str++ = '\\';
	pad_size = len_pad - ft_strlen(str_npc);
	ft_memset(str, *base, pad_size);
	ft_strlcpy(str + pad_size, str_npc, len_pad);
	free(str_npc);
	return (1 + len_pad);
}

char	*ft_strprintable(const char *src, const char *base)
{
	char	*str_main;
	char	*tmp;
	size_t	len_src;
	int		len_pad;

	len_src = ft_strlen(src);
	len_pad = ft_padsize(base);
	// str_main = ft_calloc(len_src
	// 		+ (len_src - ft_chrcount_ft(src, ft_isprint)) * (len_pad + 1)
	// 		+ 1, 1);
	str_main = malloc(len_src
			+ (len_src - ft_chrcount_ft(src, ft_isprint)) * (len_pad + 1)
			+ 1);
	if (!str_main)
		return (0);
	tmp = str_main;
	while (*src)
		if (ft_isprint(*src))
			*str_main++ = *src++;
	else
		str_main += ft_setnpc(str_main, *src++, base, len_pad);
	*str_main = 0;
	return (tmp);
}

void	ft_printable(const char *src, const char *base)
{
	char	*print;

	print = ft_strprintable(src, base);
	ft_printf("base: %s\n", base);
	ft_printf("	%s\n", print);
	free(print);
}

void	ft_printable_sign(const char *src)
{
	char	*print;

	print = ft_strprintable_sign(src);
	ft_printf("%s\n", print);
	free(print);
}

static void	allbase(const char *src)
{
	ft_printf("\nBinary\n");
	ft_printable(src, "01");
	ft_printf("\nOctal\n");
	ft_printable(src, "01234567");
	ft_printf("\nDecimal\n");
	ft_printable(src, "0123456789");
	ft_printf("\nHexadecimal\n");
	ft_printable(src, "0123456789abcdef");
}

void	static_isstupid(void)
{
	(void)allbase;
	(void)ft_printable;
	(void)ft_printable_sign;
}
// int	main(void)
// {
// 	// ft_putstr_non_printable("Coucou\ntu vas bien ?\n");
// 	// ft_printf("\n");
// 	// ft_putstr_non_printable("Hatsune \t Miku \t is   very \t cute \n");
// 	// allbase("Coucou\ntu vas bien ?\n");
// 	allbase("Hatsune \t Miku \t is   very \t cute \n");
// 	// ft_printable_sign("Coucou\ntu vas bien ?\n");
// 	// ft_printable_sign("Hatsune \t Miku \t is   very \t cute \n");
// 	// char	*print;

// 	// print = ft_strprintable("Hatsune \t Miku \t is   very \t cute \n", "0123456789");
// 	// ft_printf("\n(%s)\n", print);
// 	// free(print);
// }

void	ft_memprint(void *ptr, size_t bytes, int bytes_per_len);

int	main(void)
{
	char	*ptr;
	int		len;

	len = 6;
	ptr = malloc(len);
	ptr[len - 1] = 0;
	unsigned long	*nbr;

	nbr = (void *)ptr;
	*nbr = 77 + (256 * 105) + (256 * 256 * 107) + (256 * 256 * 256 * 117) + ((unsigned long)(256 * 256 * 256) * 256 * 62);
	ft_printf("%s\n", ptr);
}

// int	main(void)
// {
// 	int	nbr;
// 	char	*str;

// 	nbr = 256 * 256 * 65;
// 	ft_printf("memchr: %s\n", memchr(&nbr, 65, 4));
// 	ft_printf("ft_memchr: %s\n", ft_memchr(&nbr, 65, 4));
// 	for (unsigned char c = 0; c < 255; c++)
// 	{
// 		str = ft_utoa_base(c, "01");
// 		ft_printf("c: %3d; str: %08s\n", c, str);
// 		free(str);
// 	}
// 	str = ft_utoa_base(255, "01");
// 	ft_printf("c: %3d; str: %08s\n", 255, str);
// 	free(str);
// 	for (unsigned int uu = 0; uu < (unsigned int)-1; uu++)
// 	{
// 		ft_printf("nbr: %d\n", uu);
// 		ft_memprint(&uu, sizeof(uu), sizeof(uu));
// 	}
// }
