NAME := libft.a

SRCS := ${wildcard */ft_*.c}

CC := gcc

CFLAGS := -Wall -Wextra -Werror

OBJS := ${patsubst %.c, %.o, ${SRCS}}

INCLUDE := include/

HEADER := ${wildcard ${INCLUDE}*.h}

RM := rm -f

all : ${NAME}

bonus : all

${NAME} : ${OBJS}
	ar rcs $@ $^

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME} ${TEST}

re : fclean all

TEST := test

TEST_DIR := experiment/

${TEST} : ${NAME} ${TEST_DIR}${TEST}.c
	@${CC} $^ -I${INCLUDE} -I../ -o $@
	@./$@

${TEST}san : ${SRCS} ${TEST_DIR}${TEST}.c
	@${CC} $^ -I${INCLUDE} -I../ -fsanitize=address -o ${TEST}
	@./${TEST}

norm :
	@norminette ${SRCS}

PFT_DIR := libft/

${PFT_DIR} :
	mkdir $@

pft : ${NAME} ${PFT_DIR}
	cp $< ${PFT_DIR}$<

.PHONY : test pft
