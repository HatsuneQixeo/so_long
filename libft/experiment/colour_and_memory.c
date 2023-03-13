#include "libft.h"

//colour is saved as rgba with 4 individual byte in integer data type
// int	main(void)
// {
// 	unsigned int	colour;
// 	size_t			i;

// 	colour = VALUE_T;
// 	for (i = 0; i <= 256; i++)
// 	{
// 		colour = VALUE_T * i;
// 		// ft_memprint(&colour, 4);
// 		ft_printf("\n");
// 		ft_printf("%u\n", colour);
// 		ft_printf("diff: %u\n", colour - (VALUE_T * (i - 1)));
// 	}
// }

//memory and bytes
int	main(void)
{
	int	nbr;
	char	*str;

	nbr = 256 * 256 * 65;
	ft_printf("memchr: %s\n", memchr(&nbr, 65, 4));
	ft_printf("ft_memchr: %s\n", ft_memchr(&nbr, 65, 4));
	for (unsigned char c = 0; c < 255; c++)
	{
		str = ft_utoa_base(c, "01");
		ft_printf("c: %3d; str: %08s\n", c, str);
		free(str);
	}
	str = ft_utoa_base(255, "01");
	ft_printf("c: %3d; str: %08s\n", 255, str);
	free(str);
	for (unsigned short int uu = 0; uu < (unsigned short int)-1; uu++)
	{
		ft_printf("nbr: %d\n", uu);
		ft_memprint(&uu, sizeof(uu), sizeof(uu));
	}
}
