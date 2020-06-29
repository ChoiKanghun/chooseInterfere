#include "../includes/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_str_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
