#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	size = ft_strlen(s1) - i;
	while (size != 0 && ft_strchr(set, s1[size + i]))
		size--;
	str = ft_substr(s1, i, size + 1);
	if (!str)
		return (0);
	return (str);
}
