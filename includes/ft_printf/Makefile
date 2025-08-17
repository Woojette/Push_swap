CC	= cc

CFLAGS	= -Wall -Wextra -Werror

SRC	= 	ft_printf.c\
		ft_putchar.c\
		ft_putnbr_hexa_max.c\
		ft_putnbr_hexa_min.c\
		ft_putnbr_u.c\
		ft_putnbr.c\
		ft_putpointer.c\
		ft_putstr.c\

OBJ = ${SRC:.c=.o}

%.o:%.c
	${CC} ${CFLAGS}	-c $^

NAME	= libftprintf.a

all : ${NAME}

${NAME}	: ${OBJ}
	ar -rcs -o $@ $^

clean	: 
	rm -f ft_printf.o\
		ft_putchar.o\
		ft_putnbr_hexa_max.o\
		ft_putnbr_hexa_min.o\
		ft_putnbr_u.o\
		ft_putnbr.o\
		ft_putpointer.o\
		ft_putstr.o\

fclean	:	clean
	rm	-f	${NAME}

re	:	fclean
	make