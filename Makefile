NAME=		cub3D

VPATH=		src/						\
			src/parsing					\
			src/raycast					\
			src/utils

OBJDIR=		obj

INCDIR=		inc

SRC=		main.c						\
			init.c						\
			parsing.c					\
			parsing_utils.c				\
			parsing_utils2.c			\
			parsing_utils3.c			\
			map_elements.c				\
			map_description.c			\
			sonar.c						\
			checking.c					\
			error.c						\
			cleaning.c					\
			draw.c						\
			display.c					\
			mlx_utils.c					\
			player.c					\
			move.c						\
			raycast.c					\
			raycast_utils.c				\
			raycast_maths.c				\
			texture_display.c			\
			events.c					\
			minimap.c

OBJ=		${addprefix ${OBJDIR}/,		\
			${SRC:.c=.o}}

INC=		${INCDIR}/cube.h

LIB=		Libft/libft.a

CC=			cc

CFLAGS=		-Wall -Wextra -Werror -O2 -march=native -funroll-loops -ffast-math

all:		${OBJDIR} ${NAME}

lib:
			make -C Libft
			make -C mlx

${NAME}:	${OBJ} ${INC} lib
			${CC} ${OBJ} ${LIB} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}


${OBJDIR}:
			mkdir -p obj

${OBJDIR}/%.o:	%.c ${INC} Makefile
			${CC} ${CFLAGS} -c $< -o $@


clean:
			make clean -C Libft
			make clean -C mlx
			rm -rf ${OBJDIR}

fclean:		clean
			make fclean -C Libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re