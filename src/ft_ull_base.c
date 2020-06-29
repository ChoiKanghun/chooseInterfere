#include "../includes/ft_printf.h"

static char	*deal_base(unsigned long long ull_save, int base, char *dest, int count)
{
	while (ull_save != 0)
	{
		if ((ull_save % base) < 10)
			dest[count - 1] = (ull_save % base) + '0';
		else
			dest[count - 1] = (ull_save % base) + 55;
		ull_save /= base;
		count--;
	}
	return (dest);
}

char		*ft_ull_base(unsigned long long ull, int base)
{
	char			*dest;
	unsigned long long	ull_save;
	int			count;

	dest = NULL;
	count = 0;
	ull_save = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(dest = malloc(sizeof(char) * (count + 1))))
		return (0);
	dest[count] = '\0';
	dest = deal_base(ull_save, base, dest, count);
	return (dest);
}
