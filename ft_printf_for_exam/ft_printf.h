#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_strlen(char *str);
char	*ft_strnew(int size);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
void	ft_putchar(char c);
int	ft_isdigit(char c);
int	ft_size(int c);
char	*ft_fill_char(int num, int size, char *dest);
char	*ft_itoa(int num);
char	conv_hex(int n);
char	*aff_hex(unsigned int num);
int	ft_atoi(char *s);

#endif
