#include "../includes/ft_printf.h"

static int		ft_print_string(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (flags.precision >= 0)
	{
		count += ft_deal_width(flags.precision, ft_strlen(str), 0);
		count += ft_output_prec(str, flags.precision);
	}
	else
	{
		count += ft_output_prec(str, ft_strlen(str));
	}
	return (count);
}

int				ft_deal_string(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_print_string(str, flags);
	if (flags.precision >= 0)
		count += ft_deal_width(flags.width, flags.precision, 0);
	else
		count += ft_deal_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += ft_print_string(str, flags);
	return (count);
}
