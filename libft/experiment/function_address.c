#include "libft.h"

void	ft_iter(char c, int (ft)(int c))
{
	if (ft == ft_toupper)
		printf("ft_upper  : %p\n", ft_toupper);
	if (ft == ft_tolower)
		printf("ft_lower  : %p\n", ft_tolower);
	ft(c);
}

int	main(void)
{
	ft_iter('a', ft_toupper);
	ft_iter('b', ft_tolower);
	printf("main_upper: %p\n", ft_toupper);
	printf("main_lower: %p\n", ft_tolower);
}
