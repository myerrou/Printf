NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils1.c ft_printf_utils2.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<
	ar -rcs $(NAME) $@

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
