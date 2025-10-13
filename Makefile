CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

INC_DIR = includes
LIBFT_DIR = $(INC_DIR)/ft_libft
PRINTF_DIR = $(INC_DIR)/ft_printf
SRC_DIR = srcs
OBJ_DIR     = objs

SRC =	$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/ft_list.c \
		$(SRC_DIR)/ft_check.c \
		$(SRC_DIR)/ft_print.c \
		$(SRC_DIR)/ft_free.c \
		$(SRC_DIR)/ft_swap.c \
		$(SRC_DIR)/ft_rotate.c \
		$(SRC_DIR)/ft_renverse_rotate.c \
		$(SRC_DIR)/ft_push.c

OBJS        = $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBS        = $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

NAME	= push_swap

all : ${NAME}

${NAME} : ${OBJS} $(LIBS)
	${CC} ${CFLAGS} ${OBJS} $(LIBS) -o ${NAME}

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME) 

re	:	fclean
	$(MAKE)

.PHONY: all clean fclean re
