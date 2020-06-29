#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define F_WIDTH (1 << 0)
#define F_PREC (1 << 1)

typedef struct	s_data
{
	int len;
	short flags;
	char *format;
	int width;
	int prec;
	va_list ap;
}				t_data;

static int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

static int ft_strlen(char *s)
{
	int i = 0;

	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

static void *ft_calloc(size_t type, size_t numb)
{
	int i;
	void *p;

	i = type * numb;
	if (!(p = malloc(i)))
		return (NULL);
	while (i--)
		*(unsigned char*)p++ = 0;
	return (p - (type * numb));
}

static int ft_atoi(char **str)
{
	int i = 0;
	while (**str && is_number(**str))
	{
		i = i * 10 + (**str) - '0';
		(*str)++;
	}
	return (i);
}

static int sized(long int i, int radix)
{
	int len = 0;

	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / radix;
		len++;
	}
	return (len);
}

static int sized_unsi(long unsigned int i, int radix)
{
	int len = 0;

	while (i > 0)
	{
		i = i / radix;
		len++;
	}
	return (len);
}

static char *ft_itoa_base(long unsigned int i, int radix, char *base)
{
	char *str;
	int len = sized_unsi(i, radix);

	if (!(str = malloc(len + 1)))
		return (NULL);
	str[len--] = '\0';
	while (i > 0)
	{
		str[len--] = base[i % radix];
		i /= radix;
	}
	return (str);
}

static char *ft_itoa(long int i)
{
	char *str;
	int len = sized(i, 10);

	if (!(str = malloc(len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (i == 0)
		str[len] = '0';
	while (i > 0)
	{
		str[len--] = i % 10 + '0';
		i /= 10;
	}
	return (str);
}

static void ft_putstr(char *str, int size)
{
	if (str && size > 0)
		write(1, &*str, size);
}

static void ptr_string(t_data *data)
{
	char *str = va_arg(data->ap, char*);
	if (str == NULL)
		str = "(null)";
	int len = ft_strlen(str);
	if (data->flags & F_PREC)
	{
		if (data->prec < len)
			len = data->prec;
	}
	if (data->flags & F_WIDTH)
	{
		int w = -1;
		data->width = data->width - len;
		while (++w < data->width)
		{
			data->len++;
			write(1, " ", 1);
		}
	}
	if (len > 0)
	{
		data->len += len;
		ft_putstr(str, len);
	}
}

static void ptr_dec(t_data *data)
{
	long long int i = va_arg(data->ap, int);
	int neg = 0;
	if (i < 0)
	{
		i = -i;
		neg = 1;
	}
	char *str = ft_itoa(i);
	int len = ft_strlen(str);
	if (data->flags & F_WIDTH)
	{
		int w = -1;
		if ((data->flags & F_PREC) && data->width > data->prec)
			data->width -= (data->prec > 0 && len < data->prec) ? data->prec : len;
		else
			data->width = data->width - len;
		while (++w < data->width)
		{
			data->len++;
			write(1, " ", 1);
		}
	}
	if (data->flags & F_PREC)
	{
		int p = -1;
		while (++p < data->prec - len)
		{
			data->len++;
			write(1, "0", 1);
		}
	}
	if (len > 0 && !(i == 0 && (data->flags & F_PREC) && data->prec == 0))
	{
		data->len += len + neg;
		if (neg)
			write(1, "-", 1);
		ft_putstr(str, len);
	}
	else if (i == 0 && (data->flags & F_PREC) && data->prec == 0)
	{
		data->len++;
		write(1, " ", 1);
	}
	free(str);
}

static void ptr_hex(t_data *data)
{	
	long int i = va_arg(data->ap, long int);
	char *str = ft_itoa_base(i, 16, "0123456789abcdef");
	int len = ft_strlen(str);
	if (data->flags & F_WIDTH)
	{
		int w = -1;
		if (data->flags & F_PREC && data->prec == data->width)
			w = 0;
		if (data->flags & F_PREC && data->width > data->prec)
			data->width -= (data->prec > 0 && len < data->prec) ? data->prec : len;
		else
			data->width = data->width - len;
		while (++w < data->width)
		{
			data->len++;
			write(1, " ", 1);
		}
	}
	if (data->flags & F_PREC)
	{
		int p = -1;
		while (++p < data->prec - len)
		{
			data->len++;
			write(1, "0", 1);
		}
	}
	if (len > 0 && !(i == 0 && (data->flags & F_PREC) && data->prec == 0))
	{
		data->len += len;
		ft_putstr(str, len);
	}
	free(str);
}

static void handler(t_data *data)
{
	if (is_number(*data->format))
	{
		data->flags |= F_WIDTH;
		data->width = ft_atoi(&data->format);
	}
	if (*data->format == '.')
	{
		++data->format;
		data->flags |= F_PREC;
		if (is_number(*data->format))
			data->prec = ft_atoi(&data->format);
		else
			data->prec = 0;
	}
	if (*data->format == 's')
		ptr_string(data);	
	else if (*data->format == 'd')
		ptr_dec(data);
	else if (*data->format == 'x')
		ptr_hex(data);
}

int ft_printf(const char *format, ...)
{
	t_data *data;

	if (!(data = ft_calloc(sizeof(t_data), 1)))
		return (0);
	data->format = (char*)format;
	va_start(data->ap, format);
	while(*data->format)
	{
		if (*data->format == '%')
		{
			++data->format;
			if (!*data->format)
				break ;
			data->flags = 0;
			data->width = 0;
			data->prec = 0;
			handler(data);
		}
		else
		{
			data->len++;
			write(1, &*data->format, 1);
		}
		++data->format;
	}
	va_end(data->ap);
	free(data);
	return (data->len);
}

#include <stdio.h>
