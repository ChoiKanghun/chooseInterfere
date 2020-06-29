#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_is_in_type_list(char c)
{
	return (c == 'c' || c == 's' || c == 'p' ||
c == 'd' || c == 'i' || c == 'u' || c == 'x' ||
c == 'X' || c == '%');
}

int	ft_is_in_flags_list(char c)
{
	return (c == '-' || c == '.' || c == '0' || c == '*' ||
c == ' ');
}

int	ft_treat_width(int width, int minus, int has_zero)
{
	int char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		char_count++;
	}
	return (char_count);
}

int	ft_treat_char(char c, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == -1)
		ft_putchar(c);
	char_count = ft_treat_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (char_count + 1);
}

int		ft_putstrprec(char *str, int prec)
{
	int	char_count;

	char_count = 0;
	while (str[char_count] && char_count < prec)
	{
		ft_putchar(str[char_count]);
		char_count++;
	}
	return (char_count);
}

static int	ft_putpart_int(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(str), 0);
		char_count += ft_putstrprec(str, flags.dot);
	}
	else
		char_count += ft_putstrprec(str, ft_strlen(str));
	return (char_count);
}

int	ft_treat_string(char *str, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (!str)
		str = ("(null)");
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_put_part_int(str, flags);
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.width, flags.dot, 0);
	else
		char_count += ft_treat_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		char_count += ft_put_part_int(str, flags);
	return (char_count);
}

static char	*treat_base(unsigned long long ull_save, int base, char *rtn, int count)
{
	while (ull_save != 0)
	{
		if ((ull_save % base) < 10)
			rtn[count - 1] = (ull_save % base) + '0';
		else
			rtn[count - 1] = (ull_save % base) + 'a';
		ull_save /= base;
		count--;
	}
	return (rtn);
}

char	*ft_ull_base(unsigned long long ull, int base)
{
	char			*rtn;
	unsigned long long	ull_save;
	int			count;

	rtn = 0;
	count = 0;
	ull_save = ull;
	if (ull = 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(rtn = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	rtn[count] = '\0';
	rtn = treat_base(ull_save, base, rtn, count);
	return (rtn);
}

char	*ft_str_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int	ft_treat_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int	char_count;

	char_count = 0;
	if (ull == 0 && flags.dot == 0)
	{
		char_count += ft_putstrprec("0x", 2);
		return (char_count += ft_treat_width(flags.width, 0, 1));
	}
	pointer = ft_ull_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		char_count += ft_in_put_part_pointer(pointer, flags);
	char_count += ft_treat_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_in_put_part_pointer(pointer, flags);
	free(pointer);
	return (char_count);

}

static int	ft_in_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (save_i < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(d_i) - 1, 1);
	char_count += ft_putstrprec(d_i, ft_strlen(d_i));
	return (char_count);
}

static int	ft_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_int(d_i, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(d_i, save_i, flags);
	return (char_count);
}

int	ft_treat_int(int i, t_flags flags)
{
	char	*d_i;
	int	save_i;
	int	char_count;

	save_i = i;
	char_count = 0;
	if (flags.dot == 0 && i == 0)
	{
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putstrprec("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	d_i = ft_itoa(i);
	char_count += ft_put_part_int(d_i, save_i, flags);
	free(d_i);
	return (char_count);
}

int	ft_flag_dot(const char *save, int start, t_flags *flags, va_list ap)
{
	int	i;

	i = start;
	i++;
	if (save[i] == '*')
	{
		flags->dot = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(save[i]))
		{
			flags->dot = (flags->dot * 10) + (save[i] - '0');
			i++;
		}
	}
	return (i);
}

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags ft_flag_width(va_list ap, t_flags flags)
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

t_flags	ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}
