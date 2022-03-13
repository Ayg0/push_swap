CC = cc

NAME = libftprintf.a


CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c printf_utils.c

OBJS = ${SRCS:.c=.o}


.c.o:
		$(CC) $(CFLAGS) -c $<
		ar rcs $(NAME) $@

RM = rm -f

all: $(NAME)

$(NAME):	$(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

