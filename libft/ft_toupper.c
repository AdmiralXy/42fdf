#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c) && (unsigned char)(c) >= 'a' && (unsigned char)(c) <= 'z')
		return (c - 32);
	return (c);
}
