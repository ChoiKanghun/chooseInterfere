#include "../includes/ft_printf.h"

static int	ft_partial_print_int(char *d_i, int save_i, t_flags flags)
{
	int count;

	count = 0;
	if (save_i < 0 && flags.precision >= 0)
		ft_putchar('-');
	if (flags.precision >= 0)
		count += ft_deal_width(flags.precision - 1, ft_strlen(d_i) - 1, 1);
	count += ft_output_prec(d_i, ft_strlen(d_i));
	return (count);
}

static int	ft_print_int(char *d_i, int save_i, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_partial_print_int(d_i, save_i, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(d_i))
		flags.precision = ft_strlen(d_i);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_deal_width(flags.width, 0, 0);
	}
	else
		count += ft_deal_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		count += ft_partial_print_int(d_i, save_i, flags);
	return (count);
}

int			ft_deal_int(int i, t_flags flags)
{
	char	*d_i;
	int		save_i;
	int		count;

	save_i = i;
	count = 0;
	if (flags.precision == 0 && i == 0)
	{
		count += ft_deal_width(flags.width, 0, 0);
		return (count);
	}
	if (i < 0 && (flags.precision >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.precision == -1)
			ft_output_prec("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	d_i = ft_itoa(i);
	count += ft_print_int(d_i, save_i, flags);
	free(d_i);
	return (count);
}
