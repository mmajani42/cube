NAME=		cube

VPATH=		src/						\

OBJDIR=		obj

INCDIR=		inc

SRC=		main.c						\
			parsing.c					\
			init_structure.c			\

OBJ=		${addprefix ${OBJDIR}/,		\
			${SRC:.c=.o}}

INC=		${INCDIR}/cube.h

LIB=		Libft/libft.a

CC=			cc

CFLAGS=		-Wall -Wextra

all:		${OBJDIR} ${NAME}

${NAME}:	${OBJ} ${INC}
			make -C Libft
			${CC} ${OBJ} ${LIB} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

lib:
			make -C Libft
			make -C mlx

${OBJDIR}:
			mkdir -p obj

${OBJDIR}/%.o:	%.c ${INC} Makefile
			${CC} ${CFLAGS} -c $< -o $@


clean:
			make clean -C Libft
			rm -rf ${OBJDIR}

fclean:		clean
			make fclean -C Libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re