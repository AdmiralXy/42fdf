#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 0x20 && c <= 0x7e);
}
