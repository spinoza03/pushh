
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = src/main.c src/parse.c src/process_number.c src/free_array.c src/parse_utils.c src/stack_utils.c \
      libft/ft_atoi.c libft/ft_isdigit.c libft/ft_strlen.c libft/ft_split.c libft/ft_putstr.c \
      libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_strjoin.c libft/ft_memcpy.c sorting/chunk_utils.c \
	  sorting/sort_small.c sorting/indexing.c sorting/sort_large.c sorting/sort.c operations/push.c \
	  operations/reverse.c operations/rotate.c operations/swap.c

OBJ = ${SRC:.c=.o}
HEADER = includes/push_swap.h

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -I includes -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re