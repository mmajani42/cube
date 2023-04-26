NAME=       libft.a

VPATH=		src/

OBJDIR=		obj

INCDIR=		inc

SRC=		ft_isalnum.c			\
			ft_isalpha.c			\
			ft_isascii.c			\
			ft_isdigit.c			\
			ft_isprint.c			\
			ft_isspace.c			\
			ft_strlen.c				\
			ft_memset.c 			\
			ft_bzero.c				\
			ft_memcpy.c				\
			ft_memmove.c			\
			ft_strlcpy.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strcmp.c				\
			ft_strncmp.c			\
			ft_memcmp.c				\
			ft_strnstr.c			\
			ft_atoi.c				\
			ft_calloc.c				\
			ft_memchr.c				\
			ft_strdup.c				\
			ft_strndup.c			\
			ft_strlcat.c			\
			ft_substr.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_strmapi.c			\
			ft_striteri.c			\
			ft_putstr_fd.c			\
			ft_putchar_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_split.c				\
			ft_itoa.c				\
			get_next_line.c			\
			get_next_line_utils.c


OBJ=		${addprefix ${OBJDIR}/,	\
			${SRC:.c=.o}}

INC=  		${addprefix ${INCDIR}/,	\
			libft.h					\
			get_next_line.h}

CC=         gcc

CFLAGS=		-Wall -Wextra -Werror

all:		${OBJDIR} ${NAME} 

${NAME}:    ${OBJ} ${INC}
			ar rc ${NAME} ${OBJ}

${OBJDIR}:
			mkdir -p obj

${OBJDIR}/%.o:	%.c ${INC} Makefile
			${CC} ${CFLAGS} -c $< -o $@

clean:
			rm -rf ${OBJDIR}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all
		
.PHONY: 	all clean fclean re

# <cible> : <dependance>
# 		<commande>