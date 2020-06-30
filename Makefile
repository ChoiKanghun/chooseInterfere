SRCS = src/ft_deal.c \
src/ft_deal_char.c \
src/ft_deal_flags.c \
src/ft_deal_hexa.c \
src/ft_deal_int.c \
src/ft_deal_percent.c \
src/ft_deal_pointer.c \
src/ft_deal_string.c \
src/ft_deal_uint.c \
src/ft_deal_width.c \
ft_printf.c \
src/ft_printf_utils.c \
src/ft_output_prec.c \
src/ft_u_itoa.c \
src/ft_ull_base.c

LIBFT = libft

LIBFT_A = libft.a

INCLUDES = ./includes

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

ARRC = ar rc

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I$(INCLUDES)

$(NAME):	$(OBJS)
		make all -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_A) $(NAME)
		$(ARRC) $(NAME) $(OBJS)

all :		$(NAME)

bonus :		$(NAME)
		ar rc $(NAME)

clean :
			$(RM) -f $(OBJS) $(OBJS_B)
			make clean -C $(LIBFT)

fclean :	clean
			$(RM) $(NAME) $(bonus)
			make fclean -C $(LIBFT)

re :		fclean all

.PHONY : all bonus clean fclean re .c.o
