#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
int     ft_get_size(int num)
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



int     ft_strlen(char *str)
{
        if (!str)
                return (0);
        int i = 0;
        while (str[i])
                i++;
        return (i);
}


char    *ft_strnew(int size)
{
        char    *dest;
        int     i = 0;

        if (!(dest = (char *)malloc(sizeof(char) * size + 1)))
                return (NULL);
        while (i < size)
        {
                dest[i] = 0;
                i++;
        }
        dest[i] = 0;
        return (dest);
}



char    *ft_strdup(char *str)
{
        int     i;
        char    *dest;

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


char    *ft_itoa(int num)
{
        int     i;
        char    *dest;

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

int main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(4321));
	printf("%s\n", ft_itoa(-4321));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(-1));
	printf("%s\n","0 4321 -4321 1 -1");
	
	printf("%x\n", 256);
}
