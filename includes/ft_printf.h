#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_flags
{
	int		precision;
	int		already_print;
	int		type;
	int		width;
	int		minus;
	int		zero;
	int		star;
}			t_flags;

int		ft_deal(int c, t_flags flags, va_list ap);
int		ft_in_format(int c);
int		ft_in_flags(int c);
int		ft_deal_char(char c, t_flags flags);
t_flags		ft_flag_minus(t_flags flags);
t_flags		ft_flag_width(va_list ap, t_flags flags);
t_flags		ft_flag_digit(char c, t_flags flags);
int		ft_flag_precision(const char *save, int start, t_flags *flags, va_list ap);
int		ft_deal_hexa(unsigned int ui, int lower, t_flags flags);
int		ft_deal_int(int i, t_flags flags);
int		ft_deal_percent(t_flags flags);
int		ft_deal_pointer(unsigned long long ull, t_flags flags);
int		ft_deal_string(char *str, t_flags flags);
int		ft_deal_uint(unsigned int unsi, t_flags flags);
int		ft_deal_width(int width, int minus, int has_zero);
int		ft_output_prec(char *str, int prec);
int		ft_putchar(int c);
char		*ft_str_tolower(char *str);
char		*ft_u_itoa(unsigned int n);
char		*ft_ull_base(unsigned long long ull, int base);

#endif
