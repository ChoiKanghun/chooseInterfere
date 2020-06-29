#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return(i);
}

char *ft_strnew(int size)
{
	char *s;
	if (!(s = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	int i = 0;
	while (size)
	{
		s[i] = 0;
		i++;
		size--;
	}	
	s[i] = '\0';
	return(s);
}

char *ft_strcpy(char *dst, char *src)
{
	int i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return(dst);
}

char *ft_strdup(char *s)
{
	char *dst;
	dst = ft_strnew(ft_strlen(s));
	ft_strcpy(dst, s);
	return(dst);
}

char *ft_fill_char(int n, int size, char *nb)
{
	int tmp;
	int i = 0;
	size--;
	if (n < 0)
	{
		tmp = -n;
		nb[0] = '-';
	}
	else
		tmp = n;
	if (tmp >= 10)
	{
		ft_fill_char(tmp / 10, size, nb);
		nb[size] = tmp % 10 + '0';
	}
	else
		nb[size] = tmp + '0';
	return(nb);
}

int ft_size(int n)
{

	int tmp;
	int size = 0;
	if (n < 0)
	{
		tmp = -n;
		size++;
	}
	else
		tmp = n;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}

char *ft_itoa(int n)
{
	char *nb;
	int size;
	if (n == -2147483648)
		return(ft_strdup("-2147483648"));
	if (!n || n == 0)
		return(ft_strdup("0"));
	size = ft_size(n);
	nb = ft_strnew(size);
	return(ft_fill_char(n, size, nb));
}

char conv_hex(int n)
{
	if (n <= 9)
		return (n + '0');
	else
		return (n - 10 + 'a');
}

char *aff_hex(unsigned int n)
{
	unsigned int tmp = n;
	char *nb;
	int size = 0;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		size++;
	}
	if (n < 16)
		nb = ft_strnew(size + 1);
	else
		nb = ft_strnew(size);
	while (size >= 0)
	{
		tmp = n % 16;
		nb[size] = conv_hex(tmp);
		n = n / 16;
		size--;
	}
	return(nb);
}

int ft_atoi(char *s)
{
	int i = 0;
	int neg = 1;
	int nb = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '+')
		i++;
	if (s[i] == '-')
	{
		i++;
		neg = -1;
	}
	while (s[i] <= '9' && s[i] >= '0')
	{
		nb = nb * 10 + s[i] - '0';
		i++;
	}
	return (nb * neg);
}

char *ft_strjoin(char *s1, char *s2)
{
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	int len = len1 + len2;
	int i = 0;
	int j = 0;
	char *dst = ft_strnew(len);
	while (s1[i])
	{
		dst[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dst[j] = s2[i];
		i++;
		j++;
	}
	return(dst);
}

char *ft_substr(char *s, int start, int len)
{
	char *dst = ft_strnew(len);
	int i = 0;
	while(len)
	{
		dst[i] = s[start];
		i++;
		start++;
		len--;
	}
	return(dst);
}

int ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return(1);
	return(0);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

char get_format(const char *s, int i)
{
	while (s[i])
	{
		if (s[i] == 's' || s[i] == 'd' || s[i] == 'x')
			return(s[i]);
		i++;
	}
	return(0);
}

char *get_flags(const char *s, int i)
{
	char *flags = ft_strnew(100);
	int j = 0;
	while(s[i] == '.' || ft_isdigit(s[i]))
	{
		flags[j] = s[i];
		i++;
		j++;
	}
	int len = ft_strlen(flags);
	if (len <= 0)
	{
		free(flags);
		flags = NULL;
	}
	return(flags);
}

char *ft_flags(char *flags, char format, int flag_zero, int flag_neg, char *output)
{
	char *prec = ft_strnew(10);
	char *wdth = ft_strnew(10);
	int p = 0;
	int w = 0;
	int nbr_pad = 0;
	int flag_prec = 0;

	int i = 0;
	while (ft_isdigit(flags[i]))
	{
		wdth[i] = flags[i];
		i++;
	}
	if (i != 0)
		w = ft_atoi(wdth);
	int j = 0;
	if (flags[i] == '.')
	{
		flag_prec = 1;
		i++;
		while(ft_isdigit(flags[i]))
		{
			prec[j] = flags[i];
			i++;
			j++;
		}
		p = ft_atoi(prec);
	}
	if(prec)
		free(prec);
	if (wdth)
		free(wdth);

	char *padding;
	i = 0;
	//printf("s is %s\n", output);
	if (format == 's' && p < ft_strlen(output))
	{
		output = ft_substr(output, 0, p);
		//printf("s is %s\n", output);
	}
	else if (flag_zero == 1 && flag_prec == 1 && p == 0)
		output = ft_strdup("");
	else if (p > ft_strlen(output) && (format == 'd' || format == 'x') && flag_neg == 0)
	{
		nbr_pad = p - ft_strlen(output);
		padding = ft_strnew(nbr_pad);
		while(nbr_pad)
		{
			padding[i] = '0';
		       	i++;
	       		nbr_pad--;
		}
		output = ft_strjoin(padding, output);
		if (padding)
			free(padding);
	}
	else if (p > ft_strlen(output) - 1 && format == 'd' && flag_neg == 1) //attention sinon on ne rentre pas dans la condition
	{
		nbr_pad = p - ft_strlen(output);
		padding = ft_strnew(nbr_pad +2);
		padding[0] = '-';
		i = 1;
		nbr_pad++; //du coup on augmente ici
		while (nbr_pad)
		{
			padding[i] = '0';
			i++;
			nbr_pad--;
		}
		output = ft_substr(output, 1, ft_strlen(output));
		output = ft_strjoin(padding, output);
		if (padding)
			free(padding);
	}
	i = 0;
	if (w > ft_strlen(output))
	{
		nbr_pad = w - ft_strlen(output);
		padding = ft_strnew(nbr_pad);
		while(nbr_pad)
		{
			padding[i] = ' ';
			i++;
			nbr_pad--;
		}
		output =  ft_strjoin(padding, output);
		
		if (padding)
			free(padding);
	}
	return(output);
}

int ft_output(char *output)
{
	int i = 0;
	while (output[i])
	{
		ft_putchar(output[i]);
		i++;
	}
	return(i);
}

int 	ft_printf(const char *s, ...)
{
	int ret = 0;
	char *flags;
	char format;
	char *output;
	int i = 0;
	va_list ap;
	va_start(ap, s);
	int flag_zero = 0;
	int flag_neg = 0;
	int d;
	unsigned int x;

	while (s[i])
	{
		if (s[i] == '%')
		{
			format = get_format(s, i + 1);
			flags = get_flags(s, i + 1);
			if (format == 's')
			{
				output = va_arg(ap, char *);
				//printf("s is %s\n", output);
			}
			else if (format == 'd')
			{
				d = va_arg(ap, int);
			//	printf("D is %d\n", d);
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
					flag_zero = 1;
				output = aff_hex(x);
			}
			if (flags != NULL)
			{
				output = ft_flags(flags, format, flag_zero, flag_neg, output);
				i += ft_strlen(flags);
			}
			ret += ft_output(output);
			flag_zero = 0;
			flag_neg = 0;
			if (flags)
				free(flags);
			//if (output)
			//	free(output);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			ret++;
		}
		i++;
	}
	va_end(ap);
	return(ret);
}

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



