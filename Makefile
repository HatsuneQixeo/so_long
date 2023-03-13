NAME := so_long

SRCS := ${wildcard *.c}

OBJ_DIR := obj/

OBJS := ${patsubst %.c, ${OBJ_DIR}%.o, ${SRCS}}

CC := gcc

CFLAGS := -Wall -Wextra -Werror

RM := rm -rf

HEADER := so_long.h sl_image_factory.h

INCLUDE := -I libft/include

LIBFT_MAKE := make -C libft

LIBFT := libft/libft.a

all : ${OBJ_DIR} ${NAME}

${OBJ_DIR} :
	mkdir $@

${NAME} : ${OBJS}
	${LIBFT_MAKE}
	${CC} ${CFLAGS} $^ ${LIBFT} -lmlx -framework OpenGL -framework AppKit -o $@

san : ${OBJ_DIR} ${OBJS}
	${LIBFT_MAKE}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -lmlx -framework OpenGL -framework AppKit -o ${NAME} -fsanitize=address

ifndef map
map := test
endif

MAPS := maps/$(map).ber

run : all
	clear
	./${NAME} ${MAPS}

runsan : san
	clear
	./${NAME} ${MAPS}

${OBJ_DIR}%.o : %.c ${HEADER}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean :
	${LIBFT_MAKE} clean
	${RM} ${OBJ_DIR}

fclean : clean
	${LIBFT_MAKE} fclean
	${RM} ${NAME} ${EX}

re : fclean all

norm :
	norminette ${SRCS} ${HEADER} | grep -v header

test : 
	${LIBFT_MAKE} $@

sprite : 
	make -C /Users/hqixeo/Downloads $(sp)

.PHONY : ${EX}