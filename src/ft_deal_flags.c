#include "../includes/ft_printf.h"

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags	ft_flag_width(va_list ap, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int	ft_flag_precision(const char *save, int start, t_flags *flags, va_list ap)
{
	int i;

	i = start;
	i++;
	if (save[i] == '*')
	{
		flags->precision = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->precision = 0;
		while (ft_isdigit(save[i]))
			flags->precision = (flags->precision * 10) + (save[i++] - '0');
	}
	return (i);
}
