CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

ARGS = -Iinclude -lglfw -L"/Users/shmimi/goinfre/homebrew/Cellar/glfw/3.3.8/lib"


MLX42_DIRECTORY = /Users/shmimi/MLX42/
MLX42 = $(MLX42_DIRECTORY)build/libmlx42.a
MLX42_HEADERS = $(MLX42_DIRECTORY)include/

OBJS	=	${SRCS:.c=.o}

SRCS	=	gnl/get_next_line.c\
			so_long.c\
			free.c\
			utils.c\
			control.c\
			check_map.c\
			init.c\
			utils2.c\
			control_extended.c\

libft	=	make -C libft

ft_printf	=	make -C ft_printf

NAME	=	so_long

RM	=	rm -rf

all: ${NAME}

%.o : %.c
	${CC}  -c -o $@ $^

${NAME}:	${SRCS}
			@echo "\033[0;32m"
			${libft}
			@echo "\033[0;33m"
			${ft_printf}
			@echo "\033[0;36m"
			${CC} ${CFLAGS} ${SRCS} ${MLX42} ${ARGS} libft/libft.a ft_printf/libftprintf.a -o ${NAME}

clean:
		@echo "\033[1;31m"
		${libft} clean
		${ft_printf} clean
		${RM} ${OBJS}

fclean:	clean
		@echo "\033[1;31m"
		${libft} fclean
		${ft_printf} fclean
		${RM} ${NAME}

re:		fclean all