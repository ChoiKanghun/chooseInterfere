#include "../includes/ft_printf.h"

int		ft_deal_width(int width, int minus, int has_zero)
{
	int count;

	count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}
