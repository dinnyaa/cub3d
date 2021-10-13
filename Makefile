SRCS 		= $(shell find "./srcs" -name "*.c" ! -name "*bonus.c")
SRCS_BONUS	= ${shell find "./srcs" -name "*.c" ! -name "main.c"}
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
NAME		= cub3D
BONUS_NAME 	= cub_bonus
MLX			= libmlx.dylib
MLX_DIR		= mlx
CC			= gcc
RM			= rm -f
MLXFLAGS	= libmlx.dylib -framework OpenGL -framework AppKit
CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${MLX} ${OBJS}
		@${CC} ${MLXFLAGS} -o ${NAME} ${OBJS}

$(BONUS_NAME): ${MLX} ${OBJS_BONUS}
		@${CC} ${MLXFLAGS} -o ${BONUS_NAME} ${OBJS_BONUS}

$(MLX):		./${MLX_DIR}
		@cd mlx && $(MAKE) && cp ./$(MLX) ../

all:		${NAME}

bonus:		${BONUS_NAME}

clean:		
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME} ${BONUS_NAME}
			@cd mlx && $(MAKE) clean
			${RM} ./srcs/${MLX}

re:			fclean all
re_b:		fclean bonus
.PHONY:		all clean fclean bonus re re_b