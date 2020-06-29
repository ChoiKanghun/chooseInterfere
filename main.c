#include <stdio.h>
#include "includes/ft_printf.h"

int main(void)
{
	int ret;
	ret = 0;
	ret = ft_printf("%s\n%10.4x\n","ft_printf:10.4x", -150);
//	printf("%i\n", ret);


	ret = printf("%10.4x\n", -150);
//	printf("%i\n", ret);

	ret = ft_printf("%s\n%10x\n", "ft_printf :10x", 150);
//	printf("%i\n", ret);

	ret = printf("%10x\n", 150);
//	printf("%i\n", ret);

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

