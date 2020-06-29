#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

char	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	get_format(const char *str, int i)
{
	i = i + 1;
	while (str[i])
	{
		if (str[i] == 'd' || str[i] == 'x' || str[i] == 's')
			return (str[i]);
		i++;
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strnew(int size)
{
	int i;
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	if (!str)
		return (0);
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*get_flags(const char *str, int i)
{
	char	*dest;
	int	dest_len = 0;
	int	tmp = i + 1;

	while (str[tmp] == '.' || ft_isdigit(str[tmp]))
	{	
		dest_len++;
		tmp++;
	}
	if (dest_len <= 0)
	{
		return (NULL);
	}
	if (!(dest = ft_strnew(dest_len)))
		return (NULL);
	i = i + 1;
	int jndex = 0;
	while (ft_isdigit(str[i]) || str[i] == '.')
		dest[jndex++] = str[i++];
	return (dest);
}

int	get_size(int num)
{
	int	size = 0;

	if (num < 0)
	{
		num = -num;
		size++;
	}
	while (num != 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int num)
{
	char	*dest;
	int	dest_size;

	if (num == -2147483648)
	{
		int i = 0;
		dest = ft_strnew(11);
		char	*tmp = "-2147483648";
		while (tmp[i])
		{
			dest[i] = tmp[i];
			i++;
		}
		return (dest);
	}
	if (num == 0)
	{
		dest = ft_strnew(1);
		dest[0] = '0';
		return (dest);
	}
	dest_size = get_size(num);
	if (!(dest = ft_strnew(dest_size)))
		return (NULL);
	if (num < 0)
	{
		dest[0] = '-';
		num = -num;
	}
	while (num != 0)
	{
		dest[dest_size - 1] = num % 10 + '0';
		num = num / 10;
		dest_size--;
	}
	return (dest);
}

char	conv_hex(unsigned int x)
{
	if (x <= 9)
		return (x + '0');
	else
		return (x - 10 + 'a');
}

char	*aff_hex(unsigned int x)
{
	char	*dest;
	int	dest_len = 0;

	if (x == 0)
	{
		if (!(dest = ft_strnew(1)))
			return (NULL);
		dest[0] = '0';
		return (dest);
	}
	unsigned int tmp = x;
	while (tmp != 0)
	{
		dest_len++;
		tmp = tmp / 16;
	}
	if (!(dest = ft_strnew(dest_len)))
		return (NULL);
	while (x != 0)
	{
		dest[dest_len - 1] = conv_hex(x % 16);
		x /= 16;
		dest_len--;
	}
	return (dest);
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	ret = 0;
	int	minus = 1;

	if (!str)
		return (0);
	while (str[i] == ' ' && str[i] == '\n' && str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * minus);
}

char	*ft_substr(char *s1, int start, int len)
{
	int i = 0;
	char	*dest;

	while (s1[i + start] && i < len)
		i++;
	dest = ft_strnew(i);
	int jndex = 0;
	while (jndex < i)
	{
		dest[jndex] = s1[jndex + start];
		jndex++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int s1_len = ft_strlen(s1);
	int s2_len = ft_strlen(s2);
	char	*dest = ft_strnew(s1_len + s2_len);

	int i = 0;
	while (i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	int	j = 0;
	while (j < s2_len)
	{
		dest[i + j] = s2[j];
		j++;
	}
	return (dest);
}

char	*ft_flags(char *flags, char format, int flag_neg, int flag_zero, char *output)
{
	char	*dest;
	int	w = 0;
	int	p = 0;
	char	*precision;
	char	*width;
	int	nbr_pad;
	int	flag_prec = 0;

	int	width_len = 0;
	while (ft_isdigit(flags[width_len]))
		width_len++;
	width = ft_strnew(width_len);

	int	i = 0;
	while (ft_isdigit(flags[i]))
	{
		width[i] = flags[i];
		i++;
	}
	if (i != 0)
		w = ft_atoi(width);
	int	precision_len = 0;
	int	tmp = width_len;
	while (ft_isdigit(flags[tmp]) || flags[tmp] == '.')
	{
		precision_len++;
		tmp++;
	}
	precision = ft_strnew(precision_len);
	i = 0;
	if (flags[width_len] == '.')
	{
		flag_prec = 1;
		width_len++;
		while (ft_isdigit(flags[width_len]))
			precision[i++] = flags[width_len++];
		p = ft_atoi(precision);
	}
	free(width);	//문제되는가 보기
	free(precision);	//문제되는가 보기

	char	*padding;
	int	k = 0;
	if (p < ft_strlen(output) && format == 's')
		output = ft_substr(output, 0, p);
	else if (flag_zero == 1 && p == 0 && flag_prec == 1)
	{
		//free(output);
		output = ft_strnew(1);
		output[0] = '\0';
	}
	else if (p > ft_strlen(output) && flag_neg == 0 && (format == 'd' || format == 'x'))
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
		//char *tmp를 써서 free시켜보자 output도.
		free(padding);
	}
	else if (p > ft_strlen(output) - 1 && flag_neg == 1 && format == 'd')
	{
		nbr_pad = p - ft_strlen(output) + 1;
		padding = ft_strnew(nbr_pad + 1);
		padding[k++] = '-';
		while (nbr_pad)
		{
			padding[k] = '0';
			k++;
			nbr_pad--;
		}
		output = ft_substr(output, 1, ft_strlen(output) - 1);
		output = ft_strjoin(padding, output);
		free(padding);
	}
	k = 0;
	if (w > ft_strlen(output))
	{
		nbr_pad = w - ft_strlen(output);
		padding = ft_strnew(nbr_pad);
		while (nbr_pad)
		{
			padding[k] = ' ';
			nbr_pad--;
			k++;
		}
		output = ft_strjoin(padding, output);
		free(padding);
	}
	return (output);
}

int	ft_output(char *output)
{
	int i = 0;
	if (!output)
		return (0);
	while (output[i])
	{
		ft_putchar(output[i]);
		i++;
	}
	return (i);
}

int	ft_printf(const	char *str, ...)
{
	char	format;
	char	*flags;
	int	i = 0;
	char	*output;
	va_list	ap;
	va_start (ap, str);
	int	d;
	unsigned int x;
	int	flag_neg = 0;
	int	flag_zero = 0;
	int	ret = 0;

	if (!str)
		return (0);
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
				if (d == 0)
					flag_zero = 1;
				if (d < 0)
					flag_neg = 1;
				output = ft_itoa(d);
			}
			else if (format == 'x')
			{
				x = va_arg(ap, unsigned int);
				if (x == 0)
					flag_zero == 1;
				output = aff_hex(x);
			}
			if (flags != NULL)
			{
				output = ft_flags(flags, format, flag_neg, flag_zero, output);
				i += ft_strlen(flags);
			}
			ret += ft_output(output);
			flag_zero = 0;
			flag_neg = 0;
			i++;
			//if(flags)
			//free(flags);
			//if (output)
			//free(output);
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

#include <stdio.h>

int main(void)
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
