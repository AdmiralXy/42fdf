#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isalpha(c) && (unsigned char)(c) >= 'A' && (unsigned char)(c) <= 'Z')
		return (c + 32);
	return (c);
}
