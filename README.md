내가 짠 코드보다 더 예쁘게 짠 rchallie의 코드를 수도코드로 만들어봄.
https://github.com/rchallie/ft_printf

# 메인함수 - ft_printf(const char *str, …)
const char *str을 인자로 받음
필요한 필드 선언
	str을 임시로 저장할 const char *save 선언
	va_list args 선언
	int char_count 선언
save에 input을 strdup
char_count를 0으로 초기화
va_start시킴(va_start(args, input))
char_count에 ft_treat_save 함수의 리턴 값 넣음. (함수 인자는 save, args)
	ft_treat_save는 const char *save와 va_list args를 받아 save 문자열의 끝에 도달할 때까지 함수들을 적용.
va_end(args) 해줌.
인자로 받아온 (char*) save 를 free 시켜줌
char_count를 리턴.
## ft_treat_save(const char *save, va_list args)
	
필요한 필드 선언
	int	i;
	t_flags	flags;
	int	char_count;
필드 초기화
	i = 0;
	char_count = 0;
while (1)
	flags에 ft_init_flags() 의 리턴값을 담음.
	if save[i]가 널 문자를 만나면
		break;
	else if save[i] 번째가 '%' 이면서 save[i + 1] 번째가 널 문자가 아니면
		플래그 자리수 만큼 i를 더함.(최소 1을 더해서 %다음 글자를 가리키게 만듬)
		(== i에 ft_flag_parse(save, ++i, &flags, args)의 리턴값을 담음.)
		if save[i]가 `cspdiuxX%` 안에 있다면
			char_count에 save[i]에 해당하는 글자와 관련된 함수를 적용해 리턴값을 더함.
			(이 경우 save[i]에 해당하는 글자는 cspdiuxX%)
			(관련 함수는 혼자서 생각해보기. Atoi, atoi_base 등을 이용하면 됨.)
			(char_count에 ft_treatment((char)flags.type, flags, args)의 결과값을 더함.)
		else if save[i]가 '%'가 아닌 경우(즉 일반적인 경우)
			char_count에 1을 더함.
			ft_putchar(save[i])	
	end if
	i++
end while
return char_count
		
### t_flags ft_init_flags()
flags의 값들을 초기화
	flags의 dot을 -1로 초기화
	flags의 minus, star, type, width, zero를 0으로 초기화
flags를 리턴.
### ft_flag_parse(const char *save, int i, t_flags *flags, va_list args)
while save[i]가 널 문자('\0')를 만나지 않을 때까지
	if save[i]가 숫자가 아님 && save[i]가 `cspdiuxX%` 중 하나가 아님 && flag(-0. *)가 아님
		break;
	end if
	if save[i]가 문자 '0'과 같음 && flags->width가 0임 && flags->minus가 0임
		flags->zero를 1로 초기화
	end if
	if save[i]가 `.`과 같음
		`.` 뒤에 나오는 `*` 또는 숫자 개수 만큼 i를 이동시킴(더함.)
		(i에 ft_flag_dot(save, i, flags, args)의 리턴값을 담음.)
	end if
	if save[i]가 `-`와 같음
		*flags의 minus를 1로 설정하고 width에 -1을 곱함.
		(ft_flag_minus(*flags)의 결과를 적용)
		(여기서의 *은 포인터가 아니라, 인자로 받은 *flags의 안에 있는 값.)
	end if
	if save[i]가 `*`과 같음.
		*flags에 다음의 리턴 값을 담음 : ft_flag_width(args, *flags)
	end if
	if save[i]가 숫자면(ft_isdigit(save[i]))
		flags의 star가 1이면 width를 0으로 만들고 .뒤에 나오는 숫자(하나)를 담음.
		(*flags에 ft_flag_digit의 결과를 담음.)
	end if
	if save[i]가 `cspiduxX%` 중 하나라면
	(== ft_is_in_type_list(save[i]))
		flags의 type에 save[i]를 담음.
	i에 1을 더함
end while
return i
### int ft_flag_dot(const char *save, int start, t_flags *flags, va_list args)
i필드를 선언하고, start + 1로 초기화
if save[i]가 * 이면
	flags->dot 에 va_arg(args, int)를 담음.
	i를 1 증가.
else
	flags->dot에 0을 담음.
	while save[i]가 숫자인 동안
		flags->dot에 '.'뒤의 숫자를 담음.
		(== flags->dot * 10 + save[i++] - '0')
	end while
i 리턴
### t_flags ft_flag_minus(t_flags flags)
flags의 minus를 1로 설정
flags의 width에 -1을 곱함.
flags를 리턴
t_flags
{
	int	already_print;
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	star;
}
		
### t_flags ft_flag_width(va_list args, t_flags flags)
flags의 star에 1을 담음
flags의 width에 va_arg(args, int)의 결과를 담음.
if flags의 width가 0보다 작으면
	flags의 minus에 1을 담음
	flags의 width에 -1을 곱함.
end if
flags 리턴
### t_flags ft_flag_digit(char c, t_flags flags)
if flags의 star가 1이면
	flags의 width에 0을 담음.
flags의 width에 (flags.width * 10) + (c - '0')을 담음.
(== atoi 처럼 .뒤에 나오는 숫자를 담는 것.)
return flags
### int	ft_treatment(int c, t_flags flags, va_list args)
필드 설정 및 초기화 
	int char_count를 선언. 0으로 초기화
글자에 맞는 함수들을 적용
	If (c == ‘c’)
		char_count에 char를 다루는 함수를 적용.
		(== ft_treat_char(va_arg(args, int), flags)의 리턴값을 담음) 
	Else if (c == ’s’)
		char_count에 char *을 다루는 함수 적용
	이런식으로
	P, d 또는 i, u, x, X, %를 다룸.
char_count를 리턴.
		
### int ft_treat_char(char c, t_flags flags)
리턴할 필드 설정.(int char_count)
If flags의 minus가 1이면( == flags에 `-`가 껴 있으면)
	ft_putchar로 c를 출력
End if
width만큼 `0`이나 ` `를 출력한 후 출력한 개수 만큼 char_count에 담음.
(char_count 에 ft_treat_width(flags.width, 1, 0)의 결과값을 담음.)
If flags의 minus가 0이면
	c를 출력.
char_count에 1을 더한 값을 리턴.
(1을 더하는 이유는 width뿐만 아니라 c하나도 출력해야 하기 때문)
### int ft_treat_width(int width, int minus, int has_zero)
Int char_count 필드를 선언하고 0으로 초기화
While width - minus 가 0보다 큰 동안
	if has_zero가 0이 아니면(true이면)
		‘0’을 출력
	else
		‘ ‘을 출력
	width에서 1을 뺌
	char_count에 1을 더함
End while
char_count를 리턴. 
		
#### import
#include <stdarg.h>
#include <unistd.h>
