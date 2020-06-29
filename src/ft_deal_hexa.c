#include "../includes/ft_printf.h"

static int		ft_partial_print_hexa(char *hexa, t_flags flags)
{
	int count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_deal_width(flags.precision - 1, ft_strlen(hexa) - 1, 1);
	count += ft_output_prec(hexa, ft_strlen(hexa));
	return (count);
}

static int		ft_print_hexa(char *hexa, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_partial_print_hexa(hexa, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(hexa))
		flags.precision = ft_strlen(hexa);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_deal_width(flags.width, 0, 0);
	}
	else
		count += ft_deal_width(flags.width,
		ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		count += ft_partial_print_hexa(hexa, flags);
	return (count);
}

int				ft_deal_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		count;

	count = 0;
	ui = (unsigned int)(4294967295 + 1
				+ ui);
	if (flags.precision == 0 && ui == 0)
	{
		count += ft_deal_width(flags.width, 0, 0);
		return (count);
	}
	hexa = ft_ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	count += ft_print_hexa(hexa, flags);
	free(hexa);
	return (count);
}
