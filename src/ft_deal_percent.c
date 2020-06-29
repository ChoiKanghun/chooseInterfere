#include "../includes/ft_printf.h"

int		ft_deal_percent(t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_output_prec("%", 1);
	count += ft_deal_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_output_prec("%", 1);
	return (count);
}
