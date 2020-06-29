#include "libft.h"

static char	*if_n_is_zero(void)
{
	char	*res;

	if (!(res = (char *)ft_calloc(sizeof(char), 2)))
		return (NULL);
	res[0] = '0';
	return (res);
}

static char	*if_n_is_minus_max(void)
{
	char	*result;

	result = (char *)ft_calloc(sizeof(char), 12);
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	return (result);
}

static void	if_n_is_minus(char *arr, int n)
{
	size_t index;

	index = 0;
	while (n < 0)
	{
		arr[index] = (-n) % 10 + '0';
		n /= 10;
		index++;
	}
	arr[index] = '-';
	arr[index + 1] = '\0';
}

static void	if_n_is_plus(char *arr, int n)
{
	size_t index;

	index = 0;
	while (n > 0)
	{
		arr[index] = n % 10 + '0';
		n /= 10;
		index++;
	}
	arr[index] = '\0';
}

char		*ft_itoa(int n)
{
	char	*result;
	char	arr[300];
	size_t	index;
	size_t	arr_len;

	if (n == 0)
		return (if_n_is_zero());
	if (n == -2147483648)
		return (if_n_is_minus_max());
	if (n < 0)
		if_n_is_minus(arr, n);
	else
		if_n_is_plus(arr, n);
	arr_len = ft_strlen(arr);
	result = (char *)ft_calloc(sizeof(char), arr_len + 1);
	index = 0;
	while (index < arr_len)
	{
		result[index] = arr[arr_len - 1 - index];
		index++;
	}
	return (result);
}
