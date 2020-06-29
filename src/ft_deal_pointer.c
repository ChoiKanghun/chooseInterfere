#include "../includes/ft_printf.h"

static int	ft_partial_print_pointer(char *pointer, t_flags flags)
{
	int count;

	count = 0;
	count += ft_output_prec("0x", 2);
	if (flags.precision >= 0)
	{
		count += ft_deal_width(flags.precision, ft_strlen(pointer), 1);
		count += ft_output_prec(pointer, flags.precision);
	}
	else
		count += ft_output_prec(pointer, ft_strlen(pointer));
	return (count);
}

int			ft_deal_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int		count;

	count = 0;
	if (ull == 0 && flags.precision == 0)
	{
		count += ft_output_prec("0x", 2);
		return (count += ft_deal_width(flags.width, 0, 1));
	}
	pointer = ft_ull_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.precision < ft_strlen(pointer))
		flags.precision = ft_strlen(pointer);
	if (flags.minus == 1)
		count += ft_partial_print_pointer(pointer, flags);
	count += ft_deal_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		count += ft_partial_print_pointer(pointer, flags);
	free(pointer);
	return (count);
}
