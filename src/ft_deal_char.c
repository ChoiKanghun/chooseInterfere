#include "../includes/ft_printf.h"

int	ft_deal_char(char c, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = ft_deal_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}
