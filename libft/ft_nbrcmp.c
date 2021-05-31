#include "libft.h"

int	ft_nbrcmp(const int n1, const int n2)
{
	if (n1 > n2)
		return (1);
	else if (n1 < n2)
		return (-1);
	return (0);
}
