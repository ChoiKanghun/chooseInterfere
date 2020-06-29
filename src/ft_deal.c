#include "../includes/ft_printf.h"

int		ft_in_format(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_in_flags(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int		ft_deal(int c, t_flags flags, va_list ap)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_deal_char(va_arg(ap, int), flags);
	else if (c == 's')
		count = ft_deal_string(va_arg(ap, char *), flags);
	else if (c == 'p')
		count = ft_deal_pointer(va_arg(ap, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		count = ft_deal_int(va_arg(ap, int), flags);
	else if (c == 'u')
		count += ft_deal_uint((unsigned int)va_arg(ap, unsigned int),
		flags);
	else if (c == 'x')
		count += ft_deal_hexa(va_arg(ap, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_deal_hexa(va_arg(ap, unsigned int), 0, flags);
	else if (c == '%')
		count += ft_deal_percent(flags);
	return (count);
}
