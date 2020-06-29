#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_strlen(char *str)
{
	if (!str)
		return (0);
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(char	c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	get_format(const char *str, int	index)
{
	index = index + 1;
	while (str[index])
	{
		if (str[index] == 'd' || str[index] == 'x' || str[index] == 's')
			return (str[index]);
//		if (str[index] == ' ')
//			return (0);
		index++;
	}
	return (0);
}

char	*ft_strnew(int size)
{
	char	*dest;
	int	i = 0;

	if (!(dest = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		dest[i] = 0;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_flags(char const *str, int index)
{
	char	*flags; //= ft_strnew(10);
	int	jndex = 0;
	int	i;
	int	dest_len = 0;

	i = index + 1;
	while (str[i] == '.' || ft_isdigit(str[i]))
	{
		dest_len++;
		i++;
	}
	flags = ft_strnew(dest_len);
	index = index + 1;
	while (str[index] == '.' || ft_isdigit(str[index]))
	{
		flags[jndex] = str[index];
		index++;
		jndex++;
	}
	if (ft_strlen(flags) <= 0)
	{
		if (flags)
			free(flags);
		return (NULL);
	}
	return (flags);

}

char	*ft_strdup(char *str)
{
	int	i;
	char	*dest;

	i = 0;
	if (!(dest = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}

int	ft_get_size(int num)
{
	int ret;

	ret = 0;
	if (num < 0)
	{
		num = -num;
		ret++;//important!
	}
	while (num != 0)
	{
		num /= 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int num)
{
	int	i;
	char	*dest;
	
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	if (num == 0)
		return (ft_strdup("0"));
	i = ft_get_size(num);
	if (!(dest = ft_strnew(i)))
		return (NULL);
	if (num < 0)
	{
		dest[0] = '-';
		num = -num;
	}
	while (num != 0)
	{
		dest[i - 1] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (dest);
}

char	ft_conv_hex(unsigned int x)
{
	if (x <= 9)
		return (x + '0');
	else
		return (x - 10 + 'a');
}

char	*aff_hex(unsigned int x)
{
	char		*dest;
	int		dest_len;
	unsigned int	temp;

	dest_len = 0;
	if (x == 0)
		return (ft_strdup("0"));
	while (temp != 0)
	{
		temp /= 16;
		dest_len++;
	}
	if (!(dest = ft_strnew(dest_len)))
		return (NULL);
	while (x != 0)
	{
		dest[dest_len - 1] = ft_conv_hex(x % 16);
		x /= 16;
		dest_len--;
	}
	return (dest);
}

int	ft_atoi(char *str)
{
	int	ret = 0;
	int	minus = 1;
	int	i = 0;

	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * minus);
}

char	*ft_substr(char *src, int start, int len)
{
	char	*dest;
	int	dest_len = 0;

	while (dest_len < len && src[dest_len + start])
		dest_len++;
	if (!(dest = ft_strnew(dest_len)))
		return (NULL);
	int i = 0;
	while (i < dest_len)
	{
		dest[i] = src[start + i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i = 0;
	char	*dest;
	if (!(dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	int	jndex = 0;
	while (s2[jndex])
	{
		dest[i + jndex] = s2[jndex];
		jndex++; 
	}
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_flags(char *flags, char format, int flag_zero, int flag_neg, char *output)
{
	char	*width;// = ft_strnew(10); //memorize;
	int	width_len = 0;
	while (ft_isdigit(flags[width_len]))
		width_len++;
	width = ft_strnew(width_len);

	char	*precision;// = ft_strnew(10); //memorize;
	int	precision_len = 0;
	if (flags[width_len] == '.')
		while (ft_isdigit(flags[++width_len]))
			precision_len++;
	precision = ft_strnew(precision_len);
	int	w = 0;
	int	p = 0;
	int	flag_precision = 0;
	int	nbr_pad = 0;

	int	i = 0;
	while (ft_isdigit(flags[i]))
	{
		width[i] = flags[i];
		i++;
	}
	if (i != 0)
		w = ft_atoi(width);
	int	j = 0;
	if (flags[i] == '.')
	{
		flag_precision = 1;
		i++;
		while (ft_isdigit(flags[i]))
			precision[j++] = flags[i++];
		p = ft_atoi(precision);
	}
	if (width)
		free(width);
	if (precision)
		free(precision);
	
	char	*padding;
	int	k = 0;
	if (format == 's' && p < ft_strlen(output))
		output = ft_substr(output, 0, p);
	else if (p == 0 && flag_zero == 1 && flag_precision == 1)
		output = ft_strdup("");
	else if ((format == 'd' || format == 'x') && flag_neg == 0 && p > ft_strlen(output))
	{
		nbr_pad = p - ft_strlen(output);
		padding = ft_strnew(nbr_pad);
		while (nbr_pad)

		{
			padding[k] = '0';
			k++;
			nbr_pad--;
		}
		output = ft_strjoin(padding, output);
		if (padding)
			free(padding);
	}
	else if (format == 'd' && p > ft_strlen(output) - 1 && flag_neg == 1)
	{
		nbr_pad = p - ft_strlen(output) + 1;
		padding = ft_strnew(nbr_pad + 1);
		padding[0] = '-';
		k += 1;
		while (nbr_pad)
		{
			padding[k] = '0';
			nbr_pad--;
			k++;
		}
		output = ft_substr(output, 1, ft_strlen(output) - 1);
		output = ft_strjoin(padding, output);
		if (padding)
			free(padding);
	}
/*	else if (format == 'd' && p > ft_strlen(output) - 1 && flag_neg == 1)
	{
		nbr_pad = p - ft_strlen(output);
		padding = ft_strnew(nbr_pad + 1);
		padding[0] = '-';
		k = 1;
		nbr_pad++;
		while (nbr_pad)
		{
			padding[k] = '0';
			k++;
			nbr_pad--;
		}
		output = ft_substr(output, 1, ft_strlen(output));
		output = 
	}*/
	k = 0;
	if (w > ft_strlen(output))
	{
		nbr_pad = w - ft_strlen(output);
		padding = ft_strnew(nbr_pad);
		while (nbr_pad)
		{
			padding[k] = ' ';
			k++;
			nbr_pad--;
		}
		output = ft_strjoin(padding, output);
		if (padding)
			free(padding);
	}
	return (output);
}

int	ft_output(char *output)
{
	int i = 0;
	while (output[i])
	{
		ft_putchar(output[i]);
		i++;
	}
	return (i);
}

#include <stdio.h>

int	ft_printf(char const *str, ...)
{
	int	i = 0;
	int	ret = 0;
	va_list	ap;
	va_start(ap, str);
	char	format;
	char	*flags;
	char	*output;
	int	d;
	int	flag_neg = 0;
	int	flag_zero = 0;
	unsigned int	x;

	while (str[i])
	{
		if (str[i] == '%')
		{
			format = get_format(str, i);
			flags = get_flags(str, i);
			if (format == 's')
				output = va_arg(ap, char *);
			else if (format == 'd')
			{
				d = va_arg(ap, int);
				output = ft_itoa(d);
				if (d < 0)
					flag_neg = 1;
				if (d == 0)
					flag_zero = 1;
			}
			else if (format == 'x')
			{
				x = va_arg(ap, unsigned int);
				output = aff_hex(x);
				if (x == 0)
					flag_zero = 1;
			}
			if (flags != NULL)
			{
				output = ft_flags(flags, format, flag_zero, flag_neg, output);
				i += ft_strlen(flags);
			}
			ret += ft_output(output);
			flag_zero = 0;
			flag_neg = 0;
//			if (flags)
//				free(flags);
//			conditional_free(flags);
//			if (output)
//				free(output);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			ret++;
		}
		i++;
	}
	va_end(ap);
	return (ret);
}

int main()
{
	int ret;
	//ret = ft_printf("%.d\n", 0);
	//printf("%i\n", ret);

	//ret = ft_printf("%.d\n", 0);
	//printf("%i\n", ret);

	ret = ft_printf("%10.4x\n", -150);
	printf("%i\n", ret);

	ret = printf("%10.4x\n", -150);
	printf("%i\n", ret);

	ret = ft_printf("%10x\n", 150);
	printf("%i\n", ret);

	ret = printf("%10x\n", 150);
	printf("%i\n", ret);

	ret = printf("%d\n", 150);
	printf("%i\n", ret);
	
	ret = ft_printf("%10.2s\n", "toto");
	ret = ft_printf("Magic %s is %5d\n", "number", 42);
	ret = ft_printf("Hexadecimal for %d is %x\n", 42, 42);

	printf("test mine \n");
	ft_printf("ft_printf :%s\n", "A sentance");
	printf("printf :%s\n", "A sentance");
	ft_printf("ft_printf :%s\nft_printf:%s\n", "A sentence", "Second Sentence");
	printf("printf :%s\nprintf :%s\n", "A sentence", "Second Sentence");
	ft_printf("ft_printf :%s\nft_printf :%d\n", "number is", 1);
	printf("printf :%s\nprintf :%d\n", "number is", 1);
	ft_printf("ft_printf :%s\nft_printf :%x\n", "print hex 15", 15);
	ft_printf("ft_printf :%s\nft_printf :%x\n", "print hex -15", -15);
	printf("printf :%s\nprintf :%x\n", "print hex 15", 15);
	printf("printf :%s\nprintf :%x\n", "print hex -15", -15);
	ft_printf("ft_printf :%s\nft_printf:%.2s\n","precision = 2, s= hello", "hello");
	printf("printf :%s\nprintf :%.2s\n", "precision=2, s= hello", "hello");
	ft_printf("ft_printf :%s\nft_printf:%.2s\n","precision = 2, s= h", "h");
	printf("printf :%s\nprintf :%.2s\n", "precision=2, s= h", "h");
	ft_printf("ft_printf :%s\nft_printf:%.0d\n", "p = 0, d = 32", 32);
	ft_printf("ft_printf :%s\nft_printf:%.0d\n", "p = 0, d = 0", 0);
	printf("printf :%s\nprintf :%.0d\n", "p = 0, d = 32", 32);
	printf("printf :%s\nprintf :%.0d\n", "p = 0, d = 0", 0);

	ft_printf("ft_printf :%s\nft_printf :%.1d\n","p = 1, d = 1234", 1234);
	ft_printf("ft_printf :%s\nft_printf :%.1d\n","p = 1, d = -1234", -1234);
	printf("printf :%s\nprintf :%.1d\n", "p = 1, d = 1234", 1234);
	printf("printf :%s\nprintf :%.1d\n", "p = 1, d = -1234", -1234);
	ft_printf("ft_printf :%s\nft_printf :%.5d\n","p = 5, d = 1234", 1234);
	ft_printf("ft_printf :%s\nft_printf :%.5d\n","p = 5, d = -1234", -1234);
	printf("printf :%s\nprintf :%.5d\n", "p = 5, d = 1234", 1234);
	printf("printf :%s\nprintf :%.5d\n", "p = 5, d = -1234", -1234);
	ft_printf("ft_printf :%s\nft_printf :%.7d\n","p = 7, d = 1234", 1234);
	ft_printf("ft_printf :%s\nft_printf :%.7d\n","p = 7, d = -1234", -1234);
	printf("printf :%s\nprintf :%.7d\n", "p = 7, d = 1234", 1234);
	printf("printf :%s\nprintf :%.7d\n", "p = 7, d = -1234", -1234);
	printf("printf :%s\nprintf :% d\n", "% d, d = 1", 1);
	ft_printf("ft_printf :%s\nft_printf :% d\n", "% d, d = 1", 1);
	printf("printf :%s\nprintf :%x\n", "x = -1", -1);
	ft_printf("ft_printf :%s\nft_printf :%x\n", "x = -1", -1);
	printf("printf :%s\nprintf :%x\n", "x = -0", -0);
	ft_printf("ft_printf :%s\nft_printf :%x\n", "x = -0", -0);
	printf("printf :%s\nprintf :%3.d\n", "%3.d, d = 12",12);
	ft_printf("ft_printf :%s\nft_printf :%3.d\n", "%3.d, d = 12", 12);
	
	printf("printf :%s\nprintf :%2.0d\n", "width = 2, prec : 0, d = 0", 0);
	ft_printf("ft_printf :%s\nft_printf :%2.0d\n", "width = 2, prec : 0, d = 0", 0);
	printf("printf :%s\nprintf :%2.0d\n", "width = 2, prec : 0, d = 32", 32);
	ft_printf("ft_printf :%s\nft_printf :%2.0d\n", "width = 2, prec : 0, d = 32", 32);
	printf("printf :%s\nprintf :%2.3d\n", "width = 2, prec : 3, d = 0", 0);
	ft_printf("ft_printf :%s\nft_printf :%2.3d\n", "width = 2, prec : 3, d = 0", 0);
	printf("printf :%s\nprintf :%5.3d\n", "width = 5, prec : 3, d = 1", 1);
	ft_printf("ft_printf :%s\nft_printf :%5.3d\n", "width = 5, prec : 3, d = 1", 1);
	printf("printf :%s\nprintf :%5.3d\n", "width = 5, prec : 3, d = -1", -1);
	ft_printf("ft_printf :%s\nft_printf :%5.3d\n", "width = 5, prec : 3, d = -1", -1);
	printf("printf :%s\nprintf :%.5d\n", "prec : 5, d = -4321", -4321);
	ft_printf("ft_printf :%s\nft_printf :%.5d\n", "prec : 5, d = -4321", -4321);
	printf("printf :%s\nprintf :%2.2d\n", "prec : 2, width = 2, d = 43", 43);
	ft_printf("ft_printf :%s\nft_printf :%2.2d\n", "prec : 2, width = 2, d = 43", 43);
	printf("printf :%s\nprintf :%2.2d\n", "prec : 2, width = 2, d = -43", -43);
	ft_printf("ft_printf :%s\nft_printf :%2.2d\n", "prec : 2, width = 2, d = -43", -43);
	printf("printf :%s\nprintf :%4.2d\n", "prec : 2, width = 4, d = -43", -43);
	ft_printf("ft_printf :%s\nft_printf :%4.2d\n", "prec : 2, width = 4, d = -43", -43);
	printf("printf :%s\nprintf :%4.3d\n", "prec : 3, width = 4, d = -43", -43);
	ft_printf("ft_printf :%s\nft_printf :%4.3d\n", "prec : 3, width = 4, d = -43", -43);
	printf("printf :%s\nprintf :%3.5d\n", "prec : 5, width = 3, d = -43", -43);
	ft_printf("ft_printf :%s\nft_printf :%3.5d\n", "prec : 5, width = 3, d = -43", -43);
	printf("printf :%s\nprintf :%5.5d\n", "prec : 5, width = 5, d = 43", 43);
	ft_printf("ft_printf :%s\nft_printf :%5.5d\n", "prec : 5, width = 5, d = 43", 43);



}
