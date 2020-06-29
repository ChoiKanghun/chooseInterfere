#include "includes/ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.precision = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int			ft_flag_parse(const char *save, int i, t_flags *flags, va_list ap)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !ft_in_format(save[i])
		&& !ft_in_flags(save[i]))
			break ;
		if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (save[i] == '.')
			i = ft_flag_precision(save, i, flags, ap);
		if (save[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (save[i] == '*')
			*flags = ft_flag_width(ap, *flags);
		if (ft_isdigit(save[i]))
			*flags = ft_flag_digit(save[i], *flags);
		if (ft_in_format(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int			ft_deal_save(const char *save, va_list ap)
{
	int		i;
	t_flags		flags;
	int		count;

	i = 0;
	count = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!save[i])
			break ;
		else if (save[i] == '%' && save[i + 1])
		{
			i = ft_flag_parse(save, ++i, &flags, ap);
			if (ft_in_format(save[i]))
				count += ft_deal((char)flags.type, flags, ap);
			else if (save[i])
				count += ft_putchar(save[i]);
		}
		else if (save[i] != '%')
			count += ft_putchar(save[i]);
		i++;
	}
	return (count);
}

int			ft_printf(const char *input, ...)
{
	const char	*save;
	va_list		ap;
	int			count;

	save = ft_strdup(input);
	count = 0;
	va_start(ap, input);
	count += ft_deal_save(save, ap);
	va_end(ap);
	free((char *)save);
	return (count);
}
