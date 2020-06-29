#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_atoi(char *s)
{
	int i;
	i = 0;
	int ret = 0;
	int minus = 1;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '+')
		i++;
	if (s[i] == '-')
	{
		i++;
		minus = -1;
	}
	while (s[i] <= '9' && s[i] >= '0')
	{
		ret = ret * 10 + s[i] - '0';
		i++;
	}
	return (ret * minus);
}

int	ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnew(int size)
{
	char	*dest;
	int	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size)
	{
		dest[i] = 0;
		i++;
		size--;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dst, char *src)
{
	int i =0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s)
{
	char	*dest;

	dest = ft_strnew(ft_strlen(s));
	ft_strcpy(dest, s);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;
	int	len = ft_strlen(s1) + ft_strlen(s2);
	char	*dest = ft_strnew(len);
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		j++;
		i++;
	}
	return (dest);
}

char	*ft_substr(char *s, int start, int len)
{
	int	i = 0;
	char	*dest;

	dest = ft_strnew(len);
	i = 0;
	while (len)
	{
		dest[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_size(int n)
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

char	*ft_fill_char(int num, int size, char *dest)
{
	int tmp;
	size -= 1;
	if (num < 0)
	{
		tmp = -num;
		dest[0] = '-';
	}
	else
		tmp = num;
	if (tmp >= 10)
	{
		ft_fill_char(tmp / 10, size, dest);
		dest[size] = tmp % 10 + '0';
	}
	else
		dest[size] = tmp + '0';
	return (dest);
}

char	*ft_itoa(int num)
{
	char *dest;

	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	if (num == 0)
		return (ft_strdup("0"));
	int size = ft_size(num);
	dest = ft_strnew(size);
	return (ft_fill_char(num ,size, dest));
}

int	conv_hex(int n)
{
	if (n <= 9)
		return (n + '0');
	else
		return (n - 10 + 'a');
}

char	*aff_hex(unsigned long num)
{
	unsigned long tmp = num;
	char	*nb;
	int	size = 0;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		size++;
	}
	if (num < 16)
		nb = ft_strnew(size + 1);
	else
		nb = ft_strnew(size);
	while (size >= 0)
	{
		tmp = num % 16;
		nb[size] = conv_hex(tmp);
		num = num / 16;
		size--;
	}
	return (nb);
}
