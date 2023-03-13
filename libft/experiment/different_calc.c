#include "libft.h"

//Iterative is the standard
//Math is the fastest
//Recursive will segfault if the given value is too large

#define PIXEL 48

size_t	ft_size_invert_itr(int size)
{
	size_t	tile;

	tile = 1;
	while (size > PIXEL)
	{
		size -= PIXEL;
		tile++;
	}
	return (tile);
}

size_t	ft_size_centered_itr(int size)
{
	size_t	tile;

	tile = 1;
	while (size > PIXEL)
	{
		size -= (PIXEL * 2);
		tile += 2;
	}
	return (tile);
}

size_t	ft_size_invert(int size)
{
	if (size > PIXEL)
		return (1 + ft_size_invert(size - PIXEL));
	return (1);
}

size_t	ft_size_centered(int size)
{
	if (size > PIXEL)
		return (2 + ft_size_centered(size - (PIXEL * 2)));
	return (1);
}

size_t	ft_size_invert_math(size_t size)
{
	size_t	tile;

	tile = size / PIXEL;
	if (size % PIXEL)
		tile++;
	return (tile);
}

size_t	ft_size_centered_math(size_t size)
{
	size_t	tile;

	tile = (size / (PIXEL * 2)) * 2;
	if (size % (PIXEL * 2) > PIXEL)
		tile += 2;
	return (1 + tile);
}

static void	compare(long nbr)
{
	ft_printf("\nnbr: (%d)\n", nbr);
	ft_printf("\nInvert\n");
	ft_printf("	recurive:	%d\n", ft_size_invert(nbr));
	ft_printf("	iterative:	%d\n", ft_size_invert_itr(nbr));
	ft_printf("	math:		%d\n", ft_size_invert_math(nbr));
	ft_printf("\nCentered\n");
	ft_printf("	recurive:	%d\n", ft_size_centered(nbr));
	ft_printf("	iterative:	%d\n", ft_size_centered_itr(nbr));
	ft_printf("	math:		%d\n", ft_size_centered_math(nbr));
}

// Mathematics
int	main(void)
{
	compare(2147483648);
	compare(110592);
	compare(1000000);
	compare(48);
	compare(49);
	compare(96);
	compare(97);
	compare(144);
	compare145();
}
