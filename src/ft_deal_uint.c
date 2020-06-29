#include "../includes/ft_printf.h"

static int	ft_partial_print_uint(char *unsi_int, t_flags flags)
{
	int count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_deal_width(flags.precision - 1, ft_strlen(unsi_int) - 1, 1);
	count += ft_output_prec(unsi_int, ft_strlen(unsi_int));
	return (count);
}

static int	ft_print_uint(char *unsi_int, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_partial_print_uint(unsi_int, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(unsi_int))
		flags.precision = ft_strlen(unsi_int);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_deal_width(flags.width, 0, 0);
	}
	else
		count += ft_deal_width(flags.width,
		ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		count += ft_partial_print_uint(unsi_int, flags);
	return (count);
}

int			ft_deal_uint(unsigned int unsi, t_flags flags)
{
	char	*unsi_int;
	int		count;

	count = 0;
	unsi = (unsigned int)(4294967295 + 1
				+ unsi);
	if (flags.precision == 0 && unsi == 0)
	{
		count += ft_deal_width(flags.width, 0, 0);
		return (count);
	}
	unsi_int = ft_u_itoa(unsi);
	count += ft_print_uint(unsi_int, flags);
	free(unsi_int);
	return (count);
}
