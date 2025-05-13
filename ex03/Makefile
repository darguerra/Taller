CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ex03.c utils.c
OBJS = $(SRCS:.c=.o)
NAME = ex03

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re